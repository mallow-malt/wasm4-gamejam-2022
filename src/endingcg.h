#include "wasm4.h"

uint8_t play_ending(uint8_t pressedThisFrame, uint8_t gamepad) {
    tracef("test%d", pressedThisFrame);
    tracef("test%d", gamepad);
    trace("play ending");
    return 3;
}
