#include "wasm4.h"
#include "game.h"
#include "colliderdemo.h"

void start () {
  colliderdemo_start();
  /* game_start(); */
}

void update () {
  colliderdemo_update();
  /* game_update(); */
}
