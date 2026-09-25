// ============================================================================
// File: sw/pong/pong.c
// Description: Bare-metal Pong C code for NucleusRV on Zybo Z7.
//              Draws to Framebuffer at 0x00010000 and reads UART at 0x00040000.
// ============================================================================

#include <stdint.h>

// Memory Mapped Registers
#define FB_BASE   0x00010000U
#define UART_BASE 0x00040000U

#define SCREEN_W  320
#define SCREEN_H  240

// Colors in RGB565 format
#define COLOR_BLACK  0x0000
#define COLOR_WHITE  0xFFFF
#define COLOR_RED    0xF800
#define COLOR_GREEN  0x07E0
#define COLOR_BLUE   0x001F
#define COLOR_YELLOW 0xFFE0

volatile uint16_t *fb = (volatile uint16_t *)FB_BASE;
volatile uint32_t *uart = (volatile uint32_t *)UART_BASE;

// Game State Variables
int paddle1_y = 100;
int paddle2_y = 100;
int paddle_w = 6;
int paddle_h = 40;

int ball_x = 160;
int ball_y = 120;
int ball_dx = 2;
int ball_dy = 1;
int ball_size = 4;

int score1 = 0;
int score2 = 0;

// Inline utility functions
static inline void draw_rect(int x, int y, int w, int h, uint16_t color) {
    for (int i = 0; i < h; i++) {
        int py = y + i;
        if (py < 0 || py >= SCREEN_H) continue;
        for (int j = 0; j < w; j++) {
            int px = x + j;
            if (px < 0 || px >= SCREEN_W) continue;
            fb[py * SCREEN_W + px] = color;
        }
    }
}

static inline void clear_screen(uint16_t color) {
    for (int i = 0; i < SCREEN_W * SCREEN_H; i++) {
        fb[i] = color;
    }
}

// Read character from UART register (non-blocking)
static inline char uart_read_nonblock() {
    uint32_t val = *uart;
    if (val & 0x80000000U) { // Bit 31 set = valid data available
        return (char)(val & 0xFFU);
    }
    return 0;
}

void update_game() {
    // Check UART input from PC
    char key = uart_read_nonblock();
    if (key == 'w' || key == 'W') {
        paddle1_y -= 8;
        if (paddle1_y < 0) paddle1_y = 0;
    } else if (key == 's' || key == 'S') {
        paddle1_y += 8;
        if (paddle1_y > SCREEN_H - paddle_h) paddle1_y = SCREEN_H - paddle_h;
    }

    // AI logic for Right Paddle (Paddle 2)
    if (ball_y > paddle2_y + paddle_h / 2) {
        paddle2_y += 2;
        if (paddle2_y > SCREEN_H - paddle_h) paddle2_y = SCREEN_H - paddle_h;
    } else if (ball_y < paddle2_y + paddle_h / 2) {
        paddle2_y -= 2;
        if (paddle2_y < 0) paddle2_y = 0;
    }

    // Move Ball
    ball_x += ball_dx;
    ball_y += ball_dy;

    // Top / Bottom wall bounce
    if (ball_y <= 0 || ball_y >= SCREEN_H - ball_size) {
        ball_dy = -ball_dy;
    }

    // Left Paddle Collision (Player 1)
    if (ball_x <= 15 + paddle_w && ball_x >= 15 &&
        ball_y + ball_size >= paddle1_y && ball_y <= paddle1_y + paddle_h) {
        ball_dx = -ball_dx;
        ball_x = 15 + paddle_w + 1;
    }

    // Right Paddle Collision (Player 2 / AI)
    if (ball_x + ball_size >= SCREEN_W - 15 - paddle_w && ball_x <= SCREEN_W - 15 &&
        ball_y + ball_size >= paddle2_y && ball_y <= paddle2_y + paddle_h) {
        ball_dx = -ball_dx;
        ball_x = SCREEN_W - 15 - paddle_w - ball_size - 1;
    }

    // Out of bounds / Scoring
    if (ball_x < 0) { // Player 2 scores
        score2++;
        ball_x = 160;
        ball_y = 120;
        ball_dx = 2;
    } else if (ball_x > SCREEN_W) { // Player 1 scores
        score1++;
        ball_x = 160;
        ball_y = 120;
        ball_dx = -2;
    }
}

int main() {
    clear_screen(COLOR_BLACK);

    // Draw center net line
    for (int y = 0; y < SCREEN_H; y += 16) {
        draw_rect(159, y, 2, 8, COLOR_WHITE);
    }

    while (1) {
        // Erase old ball and paddles
        draw_rect(15, paddle1_y, paddle_w, paddle_h, COLOR_BLACK);
        draw_rect(SCREEN_W - 15 - paddle_w, paddle2_y, paddle_w, paddle_h, COLOR_BLACK);
        draw_rect(ball_x, ball_y, ball_size, ball_size, COLOR_BLACK);

        // Update physics & positions
        update_game();

        // Draw center net line
        for (int y = 0; y < SCREEN_H; y += 16) {
            draw_rect(159, y, 2, 8, COLOR_WHITE);
        }

        // Draw new paddles and ball
        draw_rect(15, paddle1_y, paddle_w, paddle_h, COLOR_GREEN); // Player 1 (Green)
        draw_rect(SCREEN_W - 15 - paddle_w, paddle2_y, paddle_w, paddle_h, COLOR_YELLOW); // Player 2 (Yellow)
        draw_rect(ball_x, ball_y, ball_size, ball_size, COLOR_RED); // Ball (Red)

        // Simple delay loop (~60 FPS)
        for (volatile int i = 0; i < 15000; i++);
    }

    return 0;
}
