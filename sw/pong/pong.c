#include <stdint.h>

#define FB_BASE   0x00010000U
#define UART_BASE 0x00040000U
#define SW 256
#define SH 192

#define C_BK   0x0000
#define C_WH   0xFFFF
#define C_HEAD 0xC818
#define C_SBAR 0x2945
#define C_OVL  0x18C3
#define C_P1   0x07FF
#define C_P2   0xFD20
#define C_BALL 0xF81F
#define C_LINE 0x5AEB
#define C_BDR  0x7BEF
#define C_YEL  0xFFE0
#define C_BLU  0x001F

#define HUD_H  18
#define FT     HUD_H
#define PW 6
#define PH 36
#define PX1 10
#define PX2 (SW - 10 - PW)
#define BR 4
#define GFPS 75
#define LVL_DUR (60 * GFPS)

volatile uint16_t *fb;
volatile uint32_t *uart;

static const uint8_t fnt[][7] = {
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x0E,0x11,0x13,0x15,0x19,0x11,0x0E},
    {0x04,0x0C,0x04,0x04,0x04,0x04,0x0E},
    {0x0E,0x11,0x01,0x06,0x08,0x10,0x1F},
    {0x0E,0x11,0x01,0x06,0x01,0x11,0x0E},
    {0x02,0x06,0x0A,0x12,0x1F,0x02,0x02},
    {0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E},
    {0x06,0x08,0x10,0x1E,0x11,0x11,0x0E},
    {0x1F,0x01,0x02,0x04,0x08,0x08,0x08},
    {0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E},
    {0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C},
    {0x00,0x04,0x04,0x00,0x04,0x04,0x00},
    {0x00,0x00,0x00,0x0E,0x00,0x00,0x00},
    {0x0E,0x11,0x11,0x1F,0x11,0x11,0x11},
    {0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E},
    {0x0E,0x11,0x10,0x10,0x10,0x11,0x0E},
    {0x1E,0x11,0x11,0x11,0x11,0x11,0x1E},
    {0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F},
    {0x1F,0x10,0x10,0x1E,0x10,0x10,0x10},
    {0x0E,0x11,0x10,0x17,0x11,0x11,0x0F},
    {0x11,0x11,0x11,0x1F,0x11,0x11,0x11},
    {0x0E,0x04,0x04,0x04,0x04,0x04,0x0E},
    {0x07,0x02,0x02,0x02,0x02,0x12,0x0C},
    {0x11,0x12,0x14,0x18,0x14,0x12,0x11},
    {0x10,0x10,0x10,0x10,0x10,0x10,0x1F},
    {0x11,0x1B,0x15,0x15,0x11,0x11,0x11},
    {0x11,0x11,0x19,0x15,0x13,0x11,0x11},
    {0x0E,0x11,0x11,0x11,0x11,0x11,0x0E},
    {0x1E,0x11,0x11,0x1E,0x10,0x10,0x10},
    {0x0E,0x11,0x11,0x11,0x15,0x12,0x0D},
    {0x1E,0x11,0x11,0x1E,0x14,0x12,0x11},
    {0x0E,0x11,0x10,0x0E,0x01,0x11,0x0E},
    {0x1F,0x04,0x04,0x04,0x04,0x04,0x04},
    {0x11,0x11,0x11,0x11,0x11,0x11,0x0E},
    {0x11,0x11,0x11,0x11,0x0A,0x0A,0x04},
    {0x11,0x11,0x11,0x15,0x15,0x0A,0x0A},
    {0x11,0x11,0x0A,0x04,0x0A,0x11,0x11},
    {0x11,0x11,0x0A,0x04,0x04,0x04,0x04},
    {0x1F,0x01,0x02,0x04,0x08,0x10,0x1F},
};

static int fi(char c) {
    if (c >= '0' && c <= '9') return 1 + (c - '0');
    if (c == ':') return 11;
    if (c == '-') return 12;
    if (c >= 'A' && c <= 'Z') return 13 + (c - 'A');
    return 0;
}

static inline void sp(int x, int y, uint16_t c) {
    if ((unsigned)x < SW && (unsigned)y < SH) fb[y * SW + x] = c;
}

static void fr(int x, int y, int w, int h, uint16_t c) {
    for (int j = 0; j < h; j++) {
        int py = y + j;
        if ((unsigned)py >= SH) continue;
        for (int i = 0; i < w; i++) {
            int px = x + i;
            if ((unsigned)px < SW) fb[py * SW + px] = c;
        }
    }
}

static void circ(int cx, int cy, int r, uint16_t c) {
    for (int dy = -r; dy <= r; dy++)
        for (int dx = -r; dx <= r; dx++)
            if (dx * dx + dy * dy <= r * r) sp(cx + dx, cy + dy, c);
}

static void dc(int x, int y, char ch, uint16_t c) {
    const uint8_t *g = fnt[fi(ch)];
    for (int r = 0; r < 7; r++)
        for (int b = 0; b < 5; b++)
            if (g[r] & (0x10 >> b)) sp(x + b, y + r, c);
}

static void ds(int x, int y, const char *s, uint16_t c) {
    while (*s) { dc(x, y, *s, c); x += 6; s++; }
}

static int slen(const char *s) { int n = 0; while (s[n]) n++; return n; }

static void dsc(int y, const char *s, uint16_t c) {
    ds((SW - slen(s) * 6) / 2, y, s, c);
}

static void dn2(int x, int y, int n, uint16_t c) {
    if (n > 99) n = 99;
    char b[3]; b[0] = '0' + n / 10; b[1] = '0' + n % 10; b[2] = 0;
    ds(x, y, b, c);
}

static char ur(void) {
    uint32_t v = *uart;
    return (v & 0x80000000U) ? (char)(v & 0xFF) : 0;
}

int p1y, p2y, bx, by, bdx, bdy;
int op1y, op2y, obx, oby;
int s1, s2, level, fc, hb;
int banner, stage;
char bmsg[16];

#define BANNER_FR 130

static void setmsg(const char *s) {
    int i = 0;
    while (s[i] && i < 15) { bmsg[i] = s[i]; i++; }
    bmsg[i] = 0;
}

static void set_level_msg(void) {
    char lb[8];
    lb[0]='L'; lb[1]='E'; lb[2]='V'; lb[3]='E'; lb[4]='L'; lb[5]=' '; lb[6]='0'+level; lb[7]=0;
    setmsg(lb);
}

static void set_score_msg(void) {
    char sb[16];
    sb[0]='P'; sb[1]='1'; sb[2]=' '; sb[3]='0'+(s1/10)%10; sb[4]='0'+s1%10;
    sb[5]=' '; sb[6]=' ';
    sb[7]='P'; sb[8]='2'; sb[9]=' '; sb[10]='0'+(s2/10)%10; sb[11]='0'+s2%10; sb[12]=0;
    setmsg(sb);
}

static void draw_hud(void) {
    fr(0, 0, SW, 9, C_HEAD);
    dsc(1, "PING PONG", C_WH);
    fr(0, 9, SW, 9, C_SBAR);
    ds(4, 10, "P1", C_P1);
    dn2(22, 10, s1, C_WH);
    char lb[3]; lb[0] = 'L'; lb[1] = '0' + level; lb[2] = 0;
    ds(100, 10, lb, C_WH);
    int sec = fc / GFPS;
    if (sec > 59) sec = 59;
    char tb[5]; tb[0] = '0'; tb[1] = ':'; tb[2] = '0' + sec / 10; tb[3] = '0' + sec % 10; tb[4] = 0;
    ds(118, 10, tb, C_WH);
    dn2(216, 10, s2, C_WH);
    ds(236, 10, "P2", C_P2);
}

static void draw_borders(void) {
    fr(0, FT, SW, 1, C_BDR);
    fr(0, SH - 1, SW, 1, C_BDR);
    fr(0, FT, 1, SH - FT, C_BDR);
    fr(SW - 1, FT, 1, SH - FT, C_BDR);
}

static void clear_field(void) {
    fr(1, FT + 1, SW - 2, SH - FT - 2, C_BK);
}

static void set_ball(void) {
    bx = SW / 2; by = FT + (SH - FT) / 2;
    bdx = (level == 1) ? 2 : (level == 2) ? 3 : 4;
    bdy = (level == 3) ? 2 : 1;
}

static void reset_pos(void) {
    p1y = FT + (SH - FT) / 2 - PH / 2;
    p2y = p1y;
    set_ball();
}

#define BOX_W 160
#define BOX_H 20
#define BOX_X (SW / 2 - BOX_W / 2)
#define BOX_Y (SH / 2 - BOX_H / 2)

int main(void) {
    fb = (volatile uint16_t *)FB_BASE;
    uart = (volatile uint32_t *)UART_BASE;

    level = 1; s1 = 0; s2 = 0; fc = 0; hb = 0;

    for (int i = 0; i < SW * SH; i++) fb[i] = C_BK;
    reset_pos();
    op1y = p1y; op2y = p2y; obx = bx; oby = by;

    draw_hud();
    draw_borders();

    /* start with LEVEL 1 banner (drawn every frame, auto-advances) */
    set_level_msg(); banner = 200; stage = 1;

    while (1) {
        /* erase where objects were last drawn */
        fr(PX1, op1y, PW, PH, C_BK);
        fr(PX2, op2y, PW, PH, C_BK);
        fr(obx - BR, oby - BR, BR * 2 + 1, BR * 2 + 1, C_BK);

        /* GAME UPDATES only when no banner is showing (banner freezes play) */
        if (banner == 0) {
            char key = ur();
            if (key == 'w' || key == 'W') p1y -= 6;
            if (key == 's' || key == 'S') p1y += 6;
            if (p1y < FT + 2) p1y = FT + 2;
            if (p1y > SH - 2 - PH) p1y = SH - 2 - PH;

            /* AI: capped speed + wide dead-zone so steep shots can beat it */
            int c2 = p2y + PH / 2;
            if (by > c2 + 6) p2y += 2;
            else if (by < c2 - 6) p2y -= 2;
            if (p2y < FT + 2) p2y = FT + 2;
            if (p2y > SH - 2 - PH) p2y = SH - 2 - PH;

            bx += bdx; by += bdy;
            if (by - BR <= FT + 1) { bdy = -bdy; by = FT + 2 + BR; }
            if (by + BR >= SH - 2) { bdy = -bdy; by = SH - 3 - BR; }

            /* paddle 1 hit: deflect based on where it lands on the paddle */
            if (bdx < 0 && bx - BR <= PX1 + PW && bx + BR >= PX1 &&
                by + BR >= p1y && by - BR <= p1y + PH) {
                bdx = -bdx; bx = PX1 + PW + BR + 1;
                int rel = by - (p1y + PH / 2);
                bdy = rel / 5;
                if (bdy > 3) bdy = 3; if (bdy < -3) bdy = -3;
                if (bdy == 0) bdy = (rel < 0) ? -1 : 1;
            }
            /* paddle 2 hit */
            if (bdx > 0 && bx + BR >= PX2 && bx - BR <= PX2 + PW &&
                by + BR >= p2y && by - BR <= p2y + PH) {
                bdx = -bdx; bx = PX2 - BR - 1;
                int rel = by - (p2y + PH / 2);
                bdy = rel / 5;
                if (bdy > 3) bdy = 3; if (bdy < -3) bdy = -3;
                if (bdy == 0) bdy = (rel < 0) ? -1 : 1;
            }

            if (bx - BR < 2) { s2++; set_ball(); }
            if (bx + BR > SW - 3) { s1++; set_ball(); }

            fc++;
            if (fc % GFPS == 0) draw_hud();

            if (fc >= LVL_DUR) {   /* minute over -> show score screen */
                fc = 0;
                set_score_msg();
                draw_hud();
                banner = BANNER_FR; stage = 2;
            }
        }

        /* draw field + objects every frame */
        for (int y = FT + 2; y < SH - 2; y += 8) fr(SW / 2, y, 1, 4, C_LINE);
        fr(PX1, p1y, PW, PH, C_P1);
        fr(PX2, p2y, PW, PH, C_P2);
        circ(bx, by, BR, C_BALL);
        op1y = p1y; op2y = p2y; obx = bx; oby = by;

        /* banner every frame + sequence transitions */
        if (banner > 0) {
            fr(BOX_X, BOX_Y, BOX_W, BOX_H, C_HEAD);
            fr(BOX_X + 3, BOX_Y + 3, BOX_W - 6, BOX_H - 6, C_OVL);
            dsc(BOX_Y + BOX_H / 2 - 3, bmsg, C_WH);
            banner = banner - 1;
            if (banner == 0) {
                fr(BOX_X, BOX_Y, BOX_W, BOX_H, C_BK);
                if (stage == 1) {                  /* LEVEL shown -> play */
                    stage = 0; fc = 0;
                    reset_pos();
                } else if (stage == 2) {           /* SCORE shown -> next */
                    if (level < 3) {
                        level++;
                        reset_pos();
                        set_level_msg();
                        banner = BANNER_FR; stage = 1;
                    } else {
                        if (s1 > s2) setmsg("P1 WINS");
                        else if (s2 > s1) setmsg("P2 WINS");
                        else setmsg("DRAW");
                        banner = BANNER_FR; stage = 3;
                    }
                    draw_hud();
                } else if (stage == 3) {           /* WINNER shown -> GAME END */
                    setmsg("GAME END");
                    banner = BANNER_FR; stage = 4;
                } else if (stage == 4) {           /* END shown -> restart */
                    level = 1; s1 = 0; s2 = 0;
                    reset_pos();
                    set_level_msg();
                    banner = BANNER_FR; stage = 1;
                    draw_hud();
                }
            }
        }

        hb++;
        fr(SW - 6, SH - 6, 4, 4, (hb & 1) ? C_YEL : C_BLU);

        for (volatile int i = 0; i < 15000; i++);
    }
    return 0;
}
