#ifndef UTILS_H
#define UTILS_H

signed short clampSS(signed short x, signed short min, signed short max);

unsigned char clampUC(unsigned char x, unsigned char min, unsigned char max);

float clampF(float x, float min, float max);

unsigned int clampUI(unsigned int x, unsigned int min, unsigned int max);

const char* intToString(int v, char* str);

#endif /* UTILS_H */
