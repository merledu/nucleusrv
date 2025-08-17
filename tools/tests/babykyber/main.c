#include <stdint.h>

int main() {
    // A_t matrix (4x4, 16 values)
    *(volatile uint32_t *)0x40007000 = 1;  // A_t[0][0]
    *(volatile uint32_t *)0x40007004 = 2;  // A_t[0][1]
    *(volatile uint32_t *)0x40007008 = 3;  // A_t[0][2]
    *(volatile uint32_t *)0x40007012 = 4;  // A_t[0][3]
    *(volatile uint32_t *)0x40007016 = 5;  // A_t[1][0]
    *(volatile uint32_t *)0x40007020 = 6;  // A_t[1][1]
    *(volatile uint32_t *)0x40007024 = 7;  // A_t[1][2]
    *(volatile uint32_t *)0x40007028 = 8;  // A_t[1][3]
    *(volatile uint32_t *)0x40007032 = 9;  // A_t[2][0]
    *(volatile uint32_t *)0x40007036 = 10; // A_t[2][1]
    *(volatile uint32_t *)0x40007040 = 11; // A_t[2][2]
    *(volatile uint32_t *)0x40007044 = 12; // A_t[2][3]
    *(volatile uint32_t *)0x40007048 = 13; // A_t[3][0]
    *(volatile uint32_t *)0x40007052 = 14; // A_t[3][1]
    *(volatile uint32_t *)0x40007056 = 15; // A_t[3][2]
    *(volatile uint32_t *)0x40007060 = 16; // A_t[3][3]

    // s vector (8 values)
    *(volatile uint32_t *)0x40007064 = 17; // s[0][0]
    *(volatile uint32_t *)0x40007068 = 18; // s[0][1]
    *(volatile uint32_t *)0x40007072 = 19; // s[0][2]
    *(volatile uint32_t *)0x40007076 = 20; // s[0][3]
    *(volatile uint32_t *)0x40007080 = 21; // s[1][0]
    *(volatile uint32_t *)0x40007084 = 22; // s[1][1]
    *(volatile uint32_t *)0x40007088 = 23; // s[1][2]
    *(volatile uint32_t *)0x40007092 = 24; // s[1][3]

    // e vector (8 values)
    *(volatile uint32_t *)0x40007096 = 25; // e[0][0]
    *(volatile uint32_t *)0x40007100 = 26; // e[0][1]
    *(volatile uint32_t *)0x40007104 = 27; // e[0][2]
    *(volatile uint32_t *)0x40007108 = 28; // e[0][3]
    *(volatile uint32_t *)0x40007112 = 29; // e[1][0]
    *(volatile uint32_t *)0x40007116 = 30; // e[1][1]
    *(volatile uint32_t *)0x40007120 = 31; // e[1][2]
    *(volatile uint32_t *)0x40007124 = 32; // e[1][3]

    // Trigger key generation
    *(volatile uint32_t *)0x40007356 = 0; // KEY GENERATION TRIGGER

    // Message
    *(volatile uint32_t *)0x40007128 = 42; // MESSAGE to encrypt

    // Public key for encryption (24 values)
    *(volatile uint32_t *)0x40007132 = 1;  // PK[0][0][0]
    *(volatile uint32_t *)0x40007136 = 2;  // PK[0][0][1]
    *(volatile uint32_t *)0x40007140 = 3;  // PK[0][0][2]
    *(volatile uint32_t *)0x40007144 = 4;  // PK[0][0][3]
    *(volatile uint32_t *)0x40007148 = 5;  // PK[0][1][0]
    *(volatile uint32_t *)0x40007152 = 6;  // PK[0][1][1]
    *(volatile uint32_t *)0x40007156 = 7;  // PK[0][1][2]
    *(volatile uint32_t *)0x40007160 = 8;  // PK[0][1][3]
    *(volatile uint32_t *)0x40007164 = 9;  // PK[0][2][0]
    *(volatile uint32_t *)0x40007168 = 10; // PK[0][2][1]
    *(volatile uint32_t *)0x40007172 = 11; // PK[0][2][2]
    *(volatile uint32_t *)0x40007176 = 12; // PK[0][2][3]
    *(volatile uint32_t *)0x40007180 = 13; // PK[0][3][0]
    *(volatile uint32_t *)0x40007184 = 14; // PK[0][3][1]
    *(volatile uint32_t *)0x40007188 = 15; // PK[0][3][2]
    *(volatile uint32_t *)0x40007192 = 16; // PK[0][3][3]
    *(volatile uint32_t *)0x40007196 = 17; // PK[1][0][0]
    *(volatile uint32_t *)0x40007200 = 18; // PK[1][0][1]
    *(volatile uint32_t *)0x40007204 = 19; // PK[1][0][2]
    *(volatile uint32_t *)0x40007208 = 20; // PK[1][0][3]
    *(volatile uint32_t *)0x40007212 = 21; // PK[1][1][0]
    *(volatile uint32_t *)0x40007216 = 22; // PK[1][1][1]
    *(volatile uint32_t *)0x40007220 = 23; // PK[1][1][2]
    *(volatile uint32_t *)0x40007224 = 24; // PK[1][1][3]

    // r vector (8 values)
    *(volatile uint32_t *)0x40007228 = 25; // r[0][0]
    *(volatile uint32_t *)0x40007232 = 26; // r[0][1]
    *(volatile uint32_t *)0x40007236 = 27; // r[0][2]
    *(volatile uint32_t *)0x40007240 = 28; // r[0][3]
    *(volatile uint32_t *)0x40007244 = 29; // r[1][0]
    *(volatile uint32_t *)0x40007248 = 30; // r[1][1]
    *(volatile uint32_t *)0x40007252 = 31; // r[1][2]
    *(volatile uint32_t *)0x40007256 = 32; // r[1][3]

    // e1 vector (8 values)
    *(volatile uint32_t *)0x40007260 = 33; // e1[0][0]
    *(volatile uint32_t *)0x40007264 = 34; // e1[0][1]
    *(volatile uint32_t *)0x40007268 = 35; // e1[0][2]
    *(volatile uint32_t *)0x40007272 = 36; // e1[0][3]
    *(volatile uint32_t *)0x40007276 = 37; // e1[1][0]
    *(volatile uint32_t *)0x40007280 = 38; // e1[1][1]
    *(volatile uint32_t *)0x40007284 = 39; // e1[1][2]
    *(volatile uint32_t *)0x40007288 = 40; // e1[1][3]

    // e2 vector (4 values)
    *(volatile uint32_t *)0x40007292 = 41; // e2[0]
    *(volatile uint32_t *)0x40007296 = 42; // e2[1]
    *(volatile uint32_t *)0x40007300 = 43; // e2[2]
    *(volatile uint32_t *)0x40007304 = 44; // e2[3]

    // Trigger encryption
    *(volatile uint32_t *)0x40007360 = 0; // ENCRYPTION TRIGGER

    // Ciphertext for decryption (12 values)
    *(volatile uint32_t *)0x40007308 = 1;  // CT[0][0][0]
    *(volatile uint32_t *)0x40007312 = 2;  // CT[0][0][1]
    *(volatile uint32_t *)0x40007316 = 3;  // CT[0][0][2]
    *(volatile uint32_t *)0x40007320 = 4;  // CT[0][0][3]
    *(volatile uint32_t *)0x40007324 = 5;  // CT[0][1][0]
    *(volatile uint32_t *)0x40007328 = 6;  // CT[0][1][1]
    *(volatile uint32_t *)0x40007332 = 7;  // CT[0][1][2]
    *(volatile uint32_t *)0x40007336 = 8;  // CT[0][1][3]
    *(volatile uint32_t *)0x40007340 = 9;  // CT[1][0]
    *(volatile uint32_t *)0x40007344 = 10; // CT[1][1]
    *(volatile uint32_t *)0x40007348 = 11; // CT[1][2]
    *(volatile uint32_t *)0x40007352 = 12; // CT[1][3]

    // Trigger decryption
    *(volatile uint32_t *)0x40007364 = 0; // DECRYPTION TRIGGER

    // Read result (decrypted message)
    volatile uint32_t result = *(volatile uint32_t *)0x40007144;
    (void)result; // Prevent unused warning

    while (1); // Halt

    return 0;
}