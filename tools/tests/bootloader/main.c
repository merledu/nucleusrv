// Self-Diagnosing Smart Bootloader for NucleusRV on Zybo Z7-10
#include <stdint.h>

#define UART_DATA    (*(volatile uint32_t*)0x40000000)
#define UART_STATUS  (*(volatile uint32_t*)0x40000004)
#define TIMER_MS     (*(volatile uint32_t*)0x40000010)

#define FB_MEM       ((volatile uint8_t*)0x50000000)
#define FB_MEM32     ((volatile uint32_t*)0x50000000)
#define PAL_MEM      ((volatile uint32_t*)0x50010000)

// Probe through the uncached alias so the data cache can never hide the freshly loaded binary
#define DDR3_BASE32  ((volatile uint32_t*)0x20000000)
#define WAD_BASE32   ((volatile uint32_t*)0x10800000)

// Non-blocking fire-and-forget UART (will never stall the CPU)
void uart_putc(char c) {
    UART_DATA = (uint32_t)(uint8_t)c;
}

void uart_puts(const char* s) {
    while (*s) {
        uart_putc(*s++);
    }
}

void delay_cycles(volatile int count) {
    while (count > 0) {
        count--;
        asm volatile("nop");
    }
}

void fill_rect(int y_start, int y_end, uint8_t color) {
    uint32_t word = ((uint32_t)color << 24) | ((uint32_t)color << 16) | ((uint32_t)color << 8) | color;
    for (int y = y_start; y < y_end; ++y) {
        for (int w = 0; w < 80; ++w) {
            FB_MEM32[y * 80 + w] = word;
        }
    }
}

void set_border(uint8_t color) {
    uint32_t word = ((uint32_t)color << 24) | ((uint32_t)color << 16) | ((uint32_t)color << 8) | color;
    for (int w = 0; w < 79; ++w) {
        FB_MEM32[w] = word;
        FB_MEM32[199 * 80 + w] = word;
    }
    for (int y = 0; y < 200; ++y) {
        FB_MEM[y * 320] = color;
        FB_MEM[y * 320 + 315] = color;
    }
}

int main() {
    // 1. Initialize Video Palette
    PAL_MEM[0] = 0x00000000; // 0: Black
    PAL_MEM[1] = 0x00FF0000; // 1: Red
    PAL_MEM[2] = 0x0000FF00; // 2: Green
    PAL_MEM[3] = 0x000000FF; // 3: Blue
    PAL_MEM[4] = 0x00FFFF00; // 4: Yellow
    PAL_MEM[5] = 0x0000FFFF; // 5: Cyan
    PAL_MEM[6] = 0x00FF00FF; // 6: Magenta
    PAL_MEM[7] = 0x00FFFFFF; // 7: White

    // Clear 64 KB Framebuffer to Black
    for (int i = 0; i < 16000; ++i) {
        FB_MEM32[i] = 0;
    }

    // Visual Stage 1: Core Alive -> Paint Top 50 lines GREEN (Palette 2)
    fill_rect(0, 50, 2);
    set_border(7); // White outer border (visible within screen)

    // Visual Stage 2: Middle bar YELLOW (Palette 4) -> Probing DDR3!
    fill_rect(50, 100, 4);

    uart_puts("\n[BOOT] NucleusRV Core Alive! Probing DDR3 at 0x10000000...\n");

    // Continuous DDR3 Probe Loop
    while (1) {
        // Read first 32-bit word of DDR3
        uint32_t val = DDR3_BASE32[0];

        // DOOM binary starts with nop: 0x00000013
        if (val == 0x00000013) {
            // Visual Stage 3: Paint bottom 100 lines BLUE (Palette 3)
            fill_rect(100, 200, 3);
            set_border(2); // Border GREEN

            uart_puts("[BOOT] DOOM detected at 0x10000000! Launching DOOM...\n");

            // Pause for 1 second so the blue visual confirmation is clearly visible
            delay_cycles(1500000);

            // Jump to DOOM entry point at 0x10000000
            asm volatile(
                "fence\n"
                "lui  t0, 0x10000\n"
                "jalr zero, 0(t0)\n"
            );
        } else {
            // DOOM not yet loaded in DDR3: toggle middle bar between RED and YELLOW
            fill_rect(50, 100, 1); // RED (waiting for DOOM download)
            delay_cycles(800000);
            fill_rect(50, 100, 4); // YELLOW (re-probing)
            delay_cycles(400000);
        }
    }

    return 0;
}
