#include "wasm4.h"
#include "game.h"
#include "opencg.h"
#include "endingcg.h"
#include "gamepad.h"

void start () {
    game_start();
}

uint8_t gameState = 0;

void update () {
    gamepad_update();
    uint8_t pressedThisFrame = gamepad_getPressedThisFrame();
    uint8_t gamepad = gamepad_getPressed();

    switch (gameState)
    {
    case 0: gameState = play_opening(gamepad_getPressedThisFrame());
        break;
    case 1: gameState = game_update(gamepad_getPressedThisFrame(), gamepad_getPressed());
        break;
    case 2: gameState = play_ending(gamepad_getPressedThisFrame(), gamepad_getPressed());
        break;
    default:
        *DRAW_COLORS = 0x2;
        text("Press R to restart!", 4, 150);
        break;
    }
}
