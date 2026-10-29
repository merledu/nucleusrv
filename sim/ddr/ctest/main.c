// Directed test for the DDR execution path: libc memset/memcpy (compressed code,
// computed jumps from half-word aligned auipc/jalr) at every alignment.
#include <stdint.h>
#include <string.h>

#define UART_DATA   (*(volatile uint32_t*)0x40000000)
#define UART_STATUS (*(volatile uint32_t*)0x40000004)

static void putc_(char c) { while (!(UART_STATUS & 2)); UART_DATA = (uint8_t)c; }
static void puts_(const char *s) { while (*s) putc_(*s++); }
static void hex(uint32_t v) { for (int i = 7; i >= 0; --i) putc_("0123456789ABCDEF"[(v >> (i * 4)) & 15]); }

static uint8_t buf[256] __attribute__((aligned(16)));
static uint8_t src[256] __attribute__((aligned(16)));

static void soft_divu(uint32_t a, uint32_t b, uint32_t *q, uint32_t *r) {
    uint32_t qq = 0, rr = 0;
    for (int i = 31; i >= 0; --i) {
        rr = (rr << 1) | ((a >> i) & 1);
        if (rr >= b) { rr -= b; qq |= 1u << i; }
    }
    *q = qq; *r = rr;
}
static void soft_div(uint32_t a, uint32_t b, int32_t *q, int32_t *r) {
    int na = (int32_t)a < 0, nb = (int32_t)b < 0;
    uint32_t uq, ur;
    soft_divu(na ? -a : a, nb ? -b : b, &uq, &ur);
    *q = (na != nb) ? -(int32_t)uq : (int32_t)uq;
    *r = na ? -(int32_t)ur : (int32_t)ur;
}

uint32_t dividends[64];
uint32_t divisors[16] = {125, 1, 3, 7, 10, 255, 1000, 0x10001, 13, 2, 0x7FFFFFFF, 99, 4096, 17, 125, 31};
uint32_t shifted[4];

// Same shape as the DOOM hash insert: load divisor from DDR, then remu, then use
__attribute__((noinline)) uint32_t rem_after_load(uint32_t *pa, uint32_t *pb) {
    uint32_t r;
    asm volatile("lw t0, 0(%1)\n lw t1, 0(%2)\n lw t2, 0(%2)\n remu %0, t0, t1\n"
                 : "=r"(r) : "r"(pa), "r"(pb) : "t0", "t1", "t2");
    return r;
}
__attribute__((noinline)) uint32_t rem_then_use(uint32_t *pa, uint32_t *pb, uint32_t *out) {
    uint32_t r;
    asm volatile("lw t0, 0(%1)\n lw t1, 0(%2)\n lw t2, 0(%3)\n remu %0, t0, t1\n slli %0, %0, 2\n sw %0, 0(%3)\n"
                 : "=&r"(r) : "r"(pa), "r"(pb), "r"(out) : "t0", "t1", "t2", "memory");
    return r;
}

// DOOM's hash-insert shape: load, load, remu, then use the second load's result
__attribute__((noinline)) uint32_t load_wb_during_div(uint32_t *pa, uint32_t *pb, uint32_t base) {
    uint32_t r;
    asm volatile("mv t2, %3\n lw t1, 0(%2)\n lw t2, 0(%1)\n remu %0, t2, t1\n add %0, %0, t2\n"
                 : "=&r"(r) : "r"(pa), "r"(pb), "r"(base) : "t1", "t2");
    return r;
}

// Cache tests: 64 KB = 4x the data cache, so lines are evicted dirty and refilled
static uint32_t big[16384];

static int cache_tests(void) {
    int fails = 0;
    // 1. word pattern over 64 KB, read back (every line evicted dirty at least once)
    for (int i = 0; i < 16384; ++i) big[i] = 0xC0DE0000u ^ (uint32_t)i * 2654435761u;
    for (int i = 0; i < 16384; ++i)
        if (big[i] != (0xC0DE0000u ^ (uint32_t)i * 2654435761u)) {
            if (fails++ < 5) { puts_("[CTEST] cache word FAIL i="); hex(i); puts_(" got="); hex(big[i]); putc_('\n'); }
        }
    // 2. byte and halfword stores crossing line boundaries, strided to alias cache lines
    volatile uint8_t *b = (volatile uint8_t *)big;
    for (int k = 0; k < 64; ++k) {
        uint32_t off = (uint32_t)k * 16384u + 30u + (uint32_t)k;  // near line ends, same cache index every 16 KB
        off %= sizeof(big) - 8;
        b[off] = (uint8_t)k; b[off + 1] = (uint8_t)~k; b[off + 2] = 0x5A;
        *(volatile uint16_t *)((uintptr_t)(b + off + 4) & ~1u) = (uint16_t)(0xA500 | k);
    }
    for (int k = 0; k < 64; ++k) {
        uint32_t off = ((uint32_t)k * 16384u + 30u + (uint32_t)k) % (sizeof(big) - 8);
        uint16_t h = *(volatile uint16_t *)((uintptr_t)(b + off + 4) & ~1u);
        // a later iteration may overwrite an earlier one's bytes; only check the last writer of off
        int last = 1;
        for (int j = k + 1; j < 64; ++j) {
            uint32_t o2 = ((uint32_t)j * 16384u + 30u + (uint32_t)j) % (sizeof(big) - 8);
            if (o2 + 6 > off && o2 < off + 6) last = 0;
        }
        if (last && (b[off] != (uint8_t)k || b[off + 1] != (uint8_t)~k || b[off + 2] != 0x5A || h != (uint16_t)(0xA500 | k))) {
            if (fails++ < 5) { puts_("[CTEST] cache byte FAIL k="); hex(k); putc_('\n'); }
        }
    }
    // 3. uncached alias: write through 0x2..., then read back both ways
    volatile uint32_t *unc = (volatile uint32_t *)((uintptr_t)&big[100] + 0x10000000u);
    big[100] = 0x11111111u;                 // dirty in the cache
    *unc = 0x22222222u;                     // straight to DDR (cache still holds 0x11111111)
    if (*unc != 0x22222222u) { if (fails++ < 5) puts_("[CTEST] uncached readback FAIL\n"); }
    return fails;
}

int main(void) {
    for (int k = 0; k < 64; ++k) dividends[k] = 0x9E3779B9u * (k + 1) ^ (k << 20);
    int fails = 0;
    puts_("\n[CTEST] start\n");
    for (int i = 0; i < 256; ++i) src[i] = (uint8_t)(i * 7 + 3);

    for (int off = 0; off < 16; ++off) {
        for (int len = 0; len < 80; len += 7) {
            for (int i = 0; i < 256; ++i) buf[i] = 0xEE;
            memset(buf + off, 0x5A, len);
            for (int i = 0; i < 256; ++i) {
                uint8_t want = (i >= off && i < off + len) ? 0x5A : 0xEE;
                if (buf[i] != want) {
                    if (fails++ < 10) { puts_("[CTEST] memset FAIL off="); hex(off); puts_(" len="); hex(len); puts_(" i="); hex(i); puts_(" got="); hex(buf[i]); putc_('\n'); }
                    break;
                }
            }
            for (int i = 0; i < 256; ++i) buf[i] = 0xEE;
            memcpy(buf + off, src + (off * 3 & 15), len);
            for (int i = 0; i < 256; ++i) {
                uint8_t want = (i >= off && i < off + len) ? src[(off * 3 & 15) + i - off] : 0xEE;
                if (buf[i] != want) {
                    if (fails++ < 10) { puts_("[CTEST] memcpy FAIL off="); hex(off); puts_(" len="); hex(len); puts_(" i="); hex(i); putc_('\n'); }
                    break;
                }
            }
        }
    }
    // Division: M-extension results vs. a shift-subtract reference, with operands
    // loaded from DDR right before the divide (divide stall overlapping a memory stall)
    for (int k = 0; k < 64; ++k) {
        uint32_t a = dividends[k], b = divisors[k & 15];
        uint32_t q, r;
        soft_divu(a, b, &q, &r);
        uint32_t hq = a / b, hr = a % b;
        int32_t sq = (int32_t)a / (int32_t)b, sr = (int32_t)a % (int32_t)b;
        uint32_t rr = rem_after_load(&dividends[k], &divisors[k & 15]);
        uint32_t rs = rem_then_use(&dividends[k], &divisors[k & 15], shifted);
        int32_t ssq, ssr; soft_div(a, b, &ssq, &ssr);
        uint32_t lw = load_wb_during_div(&dividends[k], &divisors[k & 15], 0xDEAD0000);
        if (lw != r + a) {
            if (fails++ < 20) { puts_("[CTEST] load-wb-during-div FAIL got="); hex(lw); puts_(" want="); hex(r + a); putc_('\n'); }
        }
        if (hq != q || hr != r || rr != r || rs != (r << 2) || shifted[0] != (r << 2) || sq != ssq || sr != ssr) {
            if (fails++ < 20) {
                puts_("[CTEST] div FAIL a="); hex(a); puts_(" b="); hex(b);
                puts_(" q="); hex(hq); puts_("/"); hex(q); puts_(" r="); hex(hr); puts_("/"); hex(r);
                puts_(" rl="); hex(rr); puts_(" ru="); hex(rs); puts_(" sq="); hex(sq); puts_("/"); hex(ssq);
                puts_(" sr="); hex(sr); puts_("/"); hex(ssr); putc_('\n');
            }
        }
    }
    fails += cache_tests();
    puts_(fails ? "[CTEST] FAILED " : "[CTEST] ALL PASS "); hex(fails); putc_('\n');
    while (1);
}
