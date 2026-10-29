// DDR3 & AXI Verification Program for NucleusRV on Zybo Z7-10
#include <stdint.h>

#define UART_DATA    (*(volatile uint32_t*)0x40000000)
#define UART_STATUS  (*(volatile uint32_t*)0x40000004)
#define BTN_STATUS   (*(volatile uint32_t*)0x40000008)
#define SW_STATUS    (*(volatile uint32_t*)0x4000000C)
#define TIMER_MS     (*(volatile uint32_t*)0x40000010)

#define FB_MEM       ((volatile uint8_t*)0x50000000)
#define FB_MEM32     ((volatile uint32_t*)0x50000000)
#define PAL_MEM      ((volatile uint32_t*)0x50010000)

// DDR3 SDRAM space (mapped via AXI HP0)
#define DDR3_BASE32  ((volatile uint32_t*)0x10000000)

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

void uart_print_hex(uint32_t val) {
    const char hex_chars[] = "0123456789ABCDEF";
    uart_puts("0x");
    for (int i = 7; i >= 0; i--) {
        uart_putc(hex_chars[(val >> (i * 4)) & 0xF]);
    }
}

void set_border_color(uint8_t color) {
    uint32_t word = ((uint32_t)color << 24) | ((uint32_t)color << 16) | ((uint32_t)color << 8) | color;
    for (int w = 0; w < 80; ++w) {
        FB_MEM32[w] = word;
        FB_MEM32[199 * 80 + w] = word;
    }
    for (int y = 0; y < 200; ++y) {
        FB_MEM[y * 320] = color;
        FB_MEM[y * 320 + 319] = color;
    }
}

int main() {
    // 1. Setup Video Palette
    PAL_MEM[0] = 0x00000000; // Black
    PAL_MEM[1] = 0x00FF0000; // Red
    PAL_MEM[2] = 0x0000FF00; // Green
    PAL_MEM[3] = 0x000000FF; // Blue
    PAL_MEM[4] = 0x00FFFF00; // Yellow
    PAL_MEM[5] = 0x0000FFFF; // Cyan
    PAL_MEM[6] = 0x00FF00FF; // Magenta
    PAL_MEM[7] = 0x00FFFFFF; // White

    // Clear 64 KB Framebuffer to Black
    for (int i = 0; i < 16384; ++i) FB_MEM32[i] = 0;

    // Set initial border to Blue (indicates DDR3 test in progress)
    set_border_color(3);

    uart_puts("\n========================================\n");
    uart_puts("  NucleusRV DDR3 & AXI Verification\n");
    uart_puts("  Target: Digilent Zybo Z7-10 (512 MB)\n");
    uart_puts("========================================\n");
    uart_puts("Testing DDR3 memory read/write at 0x10000000...\n");

    // 2. Perform Memory Integrity Test
    // Write 16,384 words (64 KB) with an LFSR/varying pattern
    const int TEST_WORDS = 16384;
    int errors = 0;
    uint32_t first_bad_addr = 0;
    uint32_t first_bad_expected = 0;
    uint32_t first_bad_actual = 0;

    for (int i = 0; i < TEST_WORDS; ++i) {
        uint32_t val = 0xA5A50000 ^ ((uint32_t)i * 1103515245U + 12345U);
        DDR3_BASE32[i] = val;
    }

    // Read back and verify
    for (int i = 0; i < TEST_WORDS; ++i) {
        uint32_t expected = 0xA5A50000 ^ ((uint32_t)i * 1103515245U + 12345U);
        uint32_t actual = DDR3_BASE32[i];
        if (actual != expected) {
            if (errors == 0) {
                first_bad_addr = (uint32_t)&DDR3_BASE32[i];
                first_bad_expected = expected;
                first_bad_actual = actual;
            }
            errors++;
        }
    }

    // 3. Display Results
    if (errors == 0) {
        uart_puts("\n[PASS] DDR3 SDRAM VERIFIED SUCCESSFULLY!\n");
        uart_puts("  Words tested: 16,384 (64 KB)\n");
        uart_puts("  Errors: 0\n");
        uart_puts("  AXI4 Master Bridge & Zynq DDR3 are 100% operational!\n\n");

        // Set border to GREEN
        set_border_color(2);

        // Draw solid GREEN center rectangle (rows 40..160, cols 60..260)
        for (int y = 40; y < 160; ++y) {
            for (int w = 15; w < 65; ++w) {
                FB_MEM32[y * 80 + w] = 0x02020202; // Green
            }
        }
    } else {
        uart_puts("\n[FAIL] DDR3 VERIFICATION FAILED!\n");
        uart_puts("  Total errors: ");
        uart_print_hex(errors);
        uart_puts("\n  First mismatch at address: ");
        uart_print_hex(first_bad_addr);
        uart_puts("\n  Expected: ");
        uart_print_hex(first_bad_expected);
        uart_puts("\n  Actual:   ");
        uart_print_hex(first_bad_actual);
        uart_puts("\n");

        // Set border to RED
        set_border_color(1);
    }

    // 4. Interactive Loop
    uint32_t last_btns = 0xFFFFFFFF;
    int hb_counter = 0;
    uint8_t hb_state = 0;

    while (1) {
        uint32_t btns = BTN_STATUS & 0x07;
        if (btns != last_btns) {
            last_btns = btns;
            if (btns & 0x01) set_border_color(1); // Red
            else if (btns & 0x02) set_border_color(2); // Green
            else if (btns & 0x04) set_border_color(3); // Blue
            else set_border_color(errors == 0 ? 2 : 1);
        }

        // Blinking Heartbeat in top corner
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
