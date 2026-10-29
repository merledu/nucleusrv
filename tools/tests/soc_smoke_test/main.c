// Smoke test program for NucleusRV DOOM SoC with Button & HDMI Video Verification
#include <stdint.h>

#define UART_DATA   (*(volatile uint32_t*)0x40000000)
#define UART_STATUS (*(volatile uint32_t*)0x40000004)
#define BTN_STATUS  (*(volatile uint32_t*)0x40000008)
#define SW_STATUS   (*(volatile uint32_t*)0x4000000C)
#define TIMER_MS    (*(volatile uint32_t*)0x40000010)

#define FB_MEM      ((volatile uint8_t*)0x50000000)
#define FB_MEM32    ((volatile uint32_t*)0x50000000)
#define PAL_MEM     ((volatile uint32_t*)0x50010000)

void uart_putc(char c) {
    while (1) {
        uint32_t st = UART_STATUS;
        asm volatile("nop; nop; nop;");
        if (st & 0x02) break;
    }
    UART_DATA = c;
}

void uart_puts(const char* s) {
    while (1) {
        char c = *s++;
        asm volatile("nop; nop; nop;");
        if (!c) break;
        uart_putc(c);
    }
}

// Function to draw outer border around 320x200 viewport
void set_border_color(uint8_t color) {
    uint32_t word = ((uint32_t)color << 24) | ((uint32_t)color << 16) | ((uint32_t)color << 8) | color;
    // Top and bottom horizontal lines
    for (int w = 0; w < 80; ++w) {
        FB_MEM32[w] = word;
        FB_MEM32[199 * 80 + w] = word;
    }
    // Left and right vertical lines
    for (int y = 0; y < 200; ++y) {
        FB_MEM[y * 320] = color;
        FB_MEM[y * 320 + 319] = color;
    }
}

int main() {
    // 1. Send banner to UART
    uart_puts("\n========================================\n");
    uart_puts("   NucleusRV DOOM SoC - Zybo Z7-10\n");
    uart_puts("   Interactive Video & Button Control\n");
    uart_puts("========================================\n");

    // 2. Set palette entries
    PAL_MEM[0] = 0x00000000; // Black
    PAL_MEM[1] = 0x00FF0000; // Red
    PAL_MEM[2] = 0x0000FF00; // Green
    PAL_MEM[3] = 0x000000FF; // Blue
    PAL_MEM[4] = 0x00FFFF00; // Yellow
    PAL_MEM[5] = 0x0000FFFF; // Cyan
    PAL_MEM[6] = 0x00FF00FF; // Magenta
    PAL_MEM[7] = 0x00FFFFFF; // White

    // 3. Clear entire 64 KB framebuffer memory to solid Black (Palette 0)
    for (int i = 0; i < 16384; ++i) {
        FB_MEM32[i] = 0x00000000;
    }

    // 4. Draw outer border around 320x200 DOOM viewport in White (Palette 7)
    set_border_color(7);

    // 5. Draw 6 vertical color bars in center (rows 20 to 180, cols 40 to 280)
    // 6 bars of 40 pixels (10 words) width each: Colors 1..6
    for (int y = 20; y < 180; ++y) {
        uint32_t* row = (uint32_t*)&FB_MEM32[y * 80 + 10]; // col 40 is word 10
        for (int bar = 0; bar < 6; ++bar) {
            uint32_t col = (uint32_t)(bar + 1);
            uint32_t word = (col << 24) | (col << 16) | (col << 8) | col;
            for (int w = 0; w < 10; ++w) {
                *row++ = word;
            }
        }
    }

    uart_puts("Test pattern rendered: 6 color bars + border.\n");
    uart_puts("Press BTN1, BTN2, BTN3 on Zybo Z7 to change border color!\n");

    uint32_t last_btns = 0xFFFFFFFF;
    uint32_t last_sws  = 0xFFFFFFFF;
    int hb_counter = 0;
    uint8_t hb_state = 0;

    while (1) {
        // --- 1. Push Button Interaction ---
        uint32_t btns = BTN_STATUS & 0x07;
        if (btns != last_btns) {
            last_btns = btns;
            if (btns & 0x01) {
                // BTN1: Red border
                set_border_color(1);
                uart_puts("[BTN1] -> Border: RED\n");
            } else if (btns & 0x02) {
                // BTN2: Green border
                set_border_color(2);
                uart_puts("[BTN2] -> Border: GREEN\n");
            } else if (btns & 0x04) {
                // BTN3: Blue border
                set_border_color(3);
                uart_puts("[BTN3] -> Border: BLUE\n");
            } else {
                // Released: White border (or Yellow if SW0 is active)
                uint8_t default_col = (last_sws & 0x01) ? 4 : 7;
                set_border_color(default_col);
            }
        }

        // --- 2. Slide Switch Interaction ---
        uint32_t sws = SW_STATUS & 0x0F;
        if (sws != last_sws) {
            last_sws = sws;
            if (sws & 0x01) {
                // SW0 ON: Yellow border default
                set_border_color(4);
            } else if ((btns & 0x07) == 0) {
                set_border_color(7);
            }
        }

        // --- 3. UART Terminal Input (if external UART connected to Pmod JE) ---
        if (UART_STATUS & 0x01) {
            char key = (char)(UART_DATA & 0xFF);
            uart_puts("Key received: '");
            uart_putc(key);
            uart_puts("'\n");

            // Change border color on key press
            uint8_t new_color = (key % 7) + 1;
            set_border_color(new_color);
        }

        // --- 4. High-Visibility Heartbeat Blinking Box ---
        // A bold 6x6 pixel block at row 4..9, col 4..9 (12x12 physical pixels on monitor)
        // Alternates between bright white (7) and pitch black (0)
        hb_counter++;
        if (hb_counter >= 100000) {
            hb_counter = 0;
            hb_state = !hb_state;
            uint8_t col = hb_state ? 7 : 0;
            for (int r = 4; r < 10; ++r) {
                for (int c = 4; c < 10; ++c) {
                    FB_MEM[r * 320 + c] = col;
                }
            }
        }
    }

    return 0;
}
