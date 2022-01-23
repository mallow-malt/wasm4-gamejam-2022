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

unsigned int clampUI(unsigned int x, unsigned int min, unsigned int max) {
  unsigned int t = x < min ? min : x;
  return t > max ? max : t;
}

const char* intToString(int v, char* str) {
  str[0] = v / 100 + 48;
  str[1] = v % 100 / 10 + 48;
  str[2] = v % 10 + 48;
  str[3] = '\0';
  return str;
}

