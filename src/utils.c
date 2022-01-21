#include "utils.h"

signed short clampSS(signed short x, signed short min, signed short max) {
  const signed short t = x < min ? min : x;
  return t > max ? max : t;
}

unsigned char clampUC(unsigned char x, unsigned char min, unsigned char max) {
  const unsigned char t = x < min ? min : x;
  return t > max ? max : t;
}

float clampF(float x, float min, float max) {
  float t = x < min ? min : x;
  return t > max ? max : t;
}

