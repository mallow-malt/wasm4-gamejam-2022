#ifndef TILECOLLIDER_H
#define TILECOLLIDER_H

#include <stdlib.h>
#include "types.h"

#define TC_NULLSTATE ' '

char tc_getState(struct tc_context context, size_t x, size_t y);
struct rect tc_getRect(struct tc_context context, struct tc_coord coords);
struct tc_coord tc_posToCoord(struct tc_context context, struct vec pos);
char tc_getStateAtPos(struct tc_context context, struct vec pos);

#endif /* TILECOLLIDER_H */
