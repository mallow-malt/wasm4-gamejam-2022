#include "wasm4.h"

// player
const uint8_t player[60] = { 0x00,0x05,0x00,0x00,0x00,0x10,0x40,0x00,0x00,0x05,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x05,0x54,0x00,0x00,0x04,0x05,0x00,0x00,0x04,0x0a,0x80,0x00,0x05,0x02,0x00,0x00,0x09,0x8a,0x00,0x00,0x02,0x68,0x00,0x0a,0x82,0x6a,0x80,0x20,0x2a,0x60,0x20,0x20,0x21,0x20,0x20,0x20,0x24,0x20,0x20,0x0a,0x80,0x0a,0x80 };

void start () {
    PALETTE[0] = 0x000000;
    PALETTE[1] = 0x32cd32;
    PALETTE[2] = 0x8b0000;
    PALETTE[3] = 0xadd8e6;
}

void update () {
    *DRAW_COLORS = 0x2341;
    blit(player, 0, 0, 16, 15, BLIT_2BPP);
}
