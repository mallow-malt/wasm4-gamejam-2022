#ifndef COLLIDER_H
#define COLLIDER_H

#include <stdbool.h>

struct vec
{
  float x;
  float y;
};

struct polygon
{
  struct vec* points;
  size_t length;
  struct vec pos;
  float angle;
  float scale;
};


extern struct vec trianglePoints[];

struct polygon makePolygon();
struct polygon makeTriangle();
struct polygon makeSquare();
void drawPolygon(struct polygon p);
struct vec findIntersect(struct vec l1_start, struct vec l1_end, struct vec l2_start, struct vec l2_end);
bool overlapP(struct polygon poly1, struct polygon poly2);
void collide(struct polygon* poly1, struct polygon* poly2);

#endif /* COLLIDER_H */
