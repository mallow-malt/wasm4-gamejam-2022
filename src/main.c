#include "wasm4.h"
#include "sprites.h"

void start () {
    PALETTE[0] = 0x000000;
    PALETTE[1] = 0x32cd32;
    PALETTE[2] = 0x8b0000;
    PALETTE[3] = 0xadd8e6;
}

void update () {
    *DRAW_COLORS = 0x4321;
    blit(PlayerFlatA.sprite, -5, 0, PlayerFlatA.width, PlayerFlatA.height, PlayerFlatA.flag);
    blit(PlayerFlatB.sprite, 16, 0, PlayerFlatB.width, PlayerFlatB.height, PlayerFlatB.flag);
    blit(PlayerTiltA.sprite, 32, 0, PlayerTiltA.width, PlayerTiltA.height, PlayerTiltA.flag);
    blit(PlayerTiltB.sprite, 48, 0, PlayerTiltB.width, PlayerTiltB.height, PlayerTiltB.flag);
    blit(FullBlockColorA.sprite, 64, 0, FullBlockColorA.width, FullBlockColorA.height, FullBlockColorA.flag);
    blit(HalfBlockColorA.sprite, 80, 0, HalfBlockColorA.width, HalfBlockColorA.height, HalfBlockColorA.flag);
}
