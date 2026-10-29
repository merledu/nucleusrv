// DOOM Generic Platform Implementation for NucleusRV on Zybo Z7
#include <stdint.h>
#include <string.h>

// NucleusRV Hardware Memory Map
#define UART_DATA_REG    (*(volatile uint32_t*)0x40000000)
#define UART_STATUS_REG  (*(volatile uint32_t*)0x40000004)
#define TIMER_MS_REG     (*(volatile uint32_t*)0x40000110)
#define FB_MEM_BASE      ((volatile uint32_t*)0x50000000)
#define PALETTE_MEM_BASE ((volatile uint32_t*)0x50010000)

#define DOOMGENERIC_RESX 320
#define DOOMGENERIC_RESY 200

// DOOM Keycodes
#define KEY_RIGHTARROW  0xae
#define KEY_LEFTARROW   0xac
#define KEY_UPARROW     0xad
#define KEY_DOWNARROW   0xaf
#define KEY_ESCAPE      27
#define KEY_ENTER       13
#define KEY_TAB         9
#define KEY_F1          (0x80 + 0x3b)
#define KEY_F2          (0x80 + 0x3c)
#define KEY_F3          (0x80 + 0x3d)
#define KEY_F4          (0x80 + 0x3e)
#define KEY_F5          (0x80 + 0x3f)
#define KEY_F6          (0x80 + 0x40)
#define KEY_F7          (0x80 + 0x41)
#define KEY_F8          (0x80 + 0x42)
#define KEY_F9          (0x80 + 0x43)
#define KEY_F10         (0x80 + 0x44)
#define KEY_F11         (0x80 + 0x57)
#define KEY_F12         (0x80 + 0x58)
#define KEY_BACKSPACE   127
#define KEY_PAUSE       0xff
#define KEY_EQUALS      0x3d
#define KEY_MINUS       0x2d
#define KEY_RSHIFT      (0x80 + 0x36)
#define KEY_RCTRL       (0x80 + 0x1d)
#define KEY_RALT        (0x80 + 0x38)
#define KEY_LALT        KEY_RALT
#define KEY_FIRE        ' '
#define KEY_USE         'e'

// Buffer provided by doomgeneric
extern uint8_t* DG_ScreenBuffer;

// -------------------------------------------------------------
// 1. Hardware Initialization
// -------------------------------------------------------------
void DG_Init() {
    // Print startup banner to UART console
    const char* banner = "\n=== Starting DOOM on NucleusRV (Zybo Z7-10) ===\n";
    while (*banner) {
        while (!(UART_STATUS_REG & 0x02)); // Wait for TX ready
        UART_DATA_REG = *banner++;
    }

    // Set fallback black/white palette until DOOM loads PLAYPAL
    for (int i = 0; i < 256; ++i) {
        PALETTE_MEM_BASE[i] = (i << 16) | (i << 8) | i;
    }
}

// -------------------------------------------------------------
// 2. Framebuffer Blit (320x200 @ 8bpp)
// -------------------------------------------------------------
void DG_DrawFrame() {
    if (!DG_ScreenBuffer) return;

    // Fast 32-bit copy of 64,000 bytes (16,000 32-bit words) into dual-port BRAM
    const uint32_t* src = (const uint32_t*)DG_ScreenBuffer;
    volatile uint32_t* dst = FB_MEM_BASE;

    for (int i = 0; i < 16000; i += 4) {
        dst[i + 0] = src[i + 0];
        dst[i + 1] = src[i + 1];
        dst[i + 2] = src[i + 2];
        dst[i + 3] = src[i + 3];
    }
}

// -------------------------------------------------------------
// 3. Timing Callbacks
// -------------------------------------------------------------
void DG_SleepMs(uint32_t ms) {
    uint32_t start = TIMER_MS_REG;
    while ((TIMER_MS_REG - start) < ms);
}

uint32_t DG_GetTicksMs() {
    return TIMER_MS_REG;
}

// -------------------------------------------------------------
// 4. Terminal Keyboard Input (Option A)
// -------------------------------------------------------------
int DG_GetKey(int *pressed, unsigned char *key) {
    // Check if a character has been received in UART RX FIFO
    if (UART_STATUS_REG & 0x01) {
        uint8_t ch = (uint8_t)(UART_DATA_REG & 0xFF);
        *pressed = 1; // Key pressed

        switch (ch) {
            // Movement (WASD + Arrows)
            case 'w': case 'W': *key = KEY_UPARROW; break;
            case 's': case 'S': *key = KEY_DOWNARROW; break;
            case 'a': case 'A': *key = KEY_LEFTARROW; break;
            case 'd': case 'D': *key = KEY_RIGHTARROW; break;

            // Actions
            case ' ':           *key = KEY_FIRE; break;
            case 'e': case 'E': *key = KEY_USE; break;
            case '\r':
            case '\n':          *key = KEY_ENTER; break;
            case 27:            *key = KEY_ESCAPE; break;

            // Numbers (Weapon selection)
            case '1': *key = '1'; break;
            case '2': *key = '2'; break;
            case '3': *key = '3'; break;
            case '4': *key = '4'; break;
            case '5': *key = '5'; break;
            case '6': *key = '6'; break;
            case '7': *key = '7'; break;

            default:  *key = ch; break;
        }
        return 1; // New key event processed
    }

    return 0; // No key available
}
