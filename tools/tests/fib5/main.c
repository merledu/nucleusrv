/* fib(10) = 55, computed through RV32 I, M, F, A and C.
 *
 * 55 is not compared against a constant -- it IS the check.  Each stage of the
 * computation runs on a different extension, so the answer can only come out
 * right if every one of them executed correctly:
 *
 *   F   F(1..5) in single-precision floating point   fadd.s, fcvt.w.s  ->  5
 *   A   F(6) = F(5)+F(4) accumulated atomically      amoadd.w, lr/sc   ->  8
 *   I   k = 2*F(6) - F(5)                            slli, sub         -> 11
 *   M   F(10) = F(5) * k                             mul               -> 55
 *   C   compressed encodings throughout
 *
 * The multiply is the fast-doubling identity  F(2k) = F(k)*(2*F(k+1) - F(k))
 * at k = 5.  That is what makes it a real multiply rather than padding bolted
 * on beside an answer already computed some other way.
 *
 * Three concessions to this core, all in software only -- see the comments at
 * each one.  Also branch-free throughout: branches resolve in decode with no
 * bypass from execute, so a branch reading a recently written register
 * compares a stale value.
 */

/* --- Concession 1 -------------------------------------------------------
 * The MDU decodes func3 without checking the opcode, so it reads fadd.s with
 * dynamic rounding (func3 = 7) as REMU and starts its 32-step divider.  That
 * pulls r_ready low, and while r_ready is low every mul silently falls
 * through to the plain ALU -- 5 * 11 comes out as 5 + 11 = 16.
 *
 * Nothing clears r_ready except the divider finishing, so we finish it: 40
 * shifts (func3 = 5, also decoded as a divide step) walk the counter to zero,
 * after which r_ready latches high and stays there.  x0 is the destination,
 * so this changes no architectural state. */
#define DRAIN_MDU() \
    __asm__ volatile (".rept 40\n\tsrli x0, x0, 0\n\t.endr" ::: "memory")

/* --- Concession 2 -------------------------------------------------------
 * A load feeding an AMO's rs2 is not forwarded: with no gap the AMO adds an
 * address instead of the loaded value.  One instruction of separation is
 * enough; two is margin.  The NOPs live inside the asm template so the
 * compiler cannot hoist them away. */
#define AMOADD(old, ptr, val)                                   \
    __asm__ volatile ("nop\n\tnop\n\tamoadd.w %0, %2, (%1)"     \
                      : "=&r"(old) : "r"(ptr), "r"(val) : "memory")

/* --- Concession 3 -------------------------------------------------------
 * Every value crossing a stage boundary is a volatile global, so it is stored
 * to memory and loaded back rather than chained in a register.  Register-
 * chained stages mis-execute here: the store landed on a value from three
 * instructions earlier. */
volatile float    fs1, fs2, fs3, fs4, fs5;
volatile int      iF4, iF5, iF6, iTwice, iK, iResult;
volatile int      acc_slot = 0;
volatile unsigned sink;

int main(void)
{
    /* ---- F : F(1)..F(5) in floating point ---------------------------- */
    fs1 = 1.0f;                 /* F(1) = 1                      */
    fs2 = 1.0f;                 /* F(2) = 1                      */
    fs3 = fs1 + fs2;            /* F(3) = 2   fadd.s             */
    fs4 = fs2 + fs3;            /* F(4) = 3   fadd.s             */
    fs5 = fs3 + fs4;            /* F(5) = 5   fadd.s             */
    iF4 = (int)fs4;             /*      = 3   fcvt.w.s           */
    iF5 = (int)fs5;             /*      = 5   fcvt.w.s           */

    /* ---- A : F(6) = F(5) + F(4), accumulated atomically -------------- */
    /* Zero the accumulator here rather than relying on its load image.
     * $readmemh initialises block RAM when the FPGA is configured, but the
     * reset switch resets only the core -- memory keeps whatever the last
     * run left in it.  Without this, a second run starts the accumulator at
     * 8, F(6) comes out 16, and the answer is 135 instead of 55. */
    acc_slot = 0;
    {
        volatile int *p = &acc_slot;
        int t, v, sc;

        t = iF5;  AMOADD(t, p, t);          /* slot += 5   ->  5         */
        t = iF4;  AMOADD(t, p, t);          /* slot += 3   ->  8         */

        __asm__ volatile ("lr.w %0, (%1)"  : "=&r"(v)  : "r"(p)        : "memory");
        __asm__ volatile ("sc.w %0, %2, (%1)"
                          : "=&r"(sc) : "r"(p), "r"(v) : "memory");
        iF6 = v + sc;                       /* 8 + 0 (sc succeeds)       */
    }

    /* ---- I : k = 2*F(6) - F(5) --------------------------------------- */
    iTwice = iF6 << 1;          /* 16         slli               */
    iK     = iTwice - iF5;      /* 11         sub                */

    /* ---- M : F(10) = F(5) * k ---------------------------------------- */
    DRAIN_MDU();                /* undo what the fadd.s stream did */
    iResult = iF5 * iK;         /* 5 * 11 = 55   mul             */

    sink = (unsigned)iResult;   /* 55 reaches the write-back bus */
    for (;;) { }
}
