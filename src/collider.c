#include "wasm4.h"
#include <stdbool.h>
#include "collider.h"
#include <math.h>

struct vec linePoints[] = {
  {0.0f, 0.0f},
  {1.0f, 0.0f}
};

struct vec lineCenter = { 0.5f, 0.0f };

struct vec trianglePoints[] = {
  {1.0f, 0.0f},
  {-0.5f, 0.866025f},
  {-0.5f, -0.866025f}
};

struct vec triangleCenter = { 0.0f, 0.0f };

struct vec squarePoints[] = {
  {0.0f, 0.0f},
  {1.0f, 0.0f},
  {1.0f, 1.0f},
  {0.0f, 1.0f},
};

struct vec squareCenter = { 0.5f, 0.5f };

/* struct vec squarePoints[] = { */
/*   {-0.5f, -0.5f}, */
/*   {0.5f, -0.5f}, */
/*   {0.5f, 0.5f}, */
/*   {-0.5f, 0.5f}, */
/* }; */

struct polygon makePolygon(struct vec* points, size_t length, struct vec center)
{
  struct vec emptyPos = { 0.0f, 0.0f };
  struct polygon res;
  res.points = points;
  res.length = length;
  res.pos = emptyPos;
  res.angle = 0.0f;
  res.center = center;
  return res;
}

struct polygon makeLine()
{
  return makePolygon(linePoints, sizeof(linePoints)/sizeof(linePoints[0]), lineCenter);
}

struct polygon makeTriangle()
{
  return makePolygon(trianglePoints, sizeof(trianglePoints)/sizeof(trianglePoints[0]), triangleCenter);
}

struct polygon makeSquare()
{
  return makePolygon(squarePoints, sizeof(squarePoints)/sizeof(squarePoints[0]), squareCenter);
}

struct vec applyTransform(struct vec pnt, float scale, float angle, struct vec offset)
{
  struct vec res = {
    ((pnt.x * cosf(angle)) - (pnt.y * sinf(angle))) * scale + offset.x,
    ((pnt.x * sinf(angle)) + (pnt.y * cosf(angle))) * scale + offset.y,
  };
  return res;
}

void drawPolygon(struct polygon p)
{
  for (size_t i = 0; i < p.length; ++i) {
    struct vec pnt1 = applyTransform(p.points[i], p.scale, p.angle, p.pos);
    struct vec pnt2 = applyTransform(p.points[(i+1) % p.length], p.scale, p.angle, p.pos);
    
    line(pnt1.x,
         pnt1.y,
         pnt2.x,
         pnt2.y);
  }
}

// res.x is where l1 is intersected, res.y is where l2 is intersected
// if component is >= 0 and < 1, that line was intersected in the segment
// if both components are >= 0 and < 1, those line segments intersect
struct vec findIntersect(struct vec l1_start, struct vec l1_end, struct vec l2_start, struct vec l2_end)
{
  float h = (l2_end.x - l2_start.x) * (l1_start.y - l1_end.y) - (l1_start.x - l1_end.x) * (l2_end.y - l2_start.y);
  float t1 = ((l2_start.y - l2_end.y) * (l1_start.x - l2_start.x) + (l2_end.x - l2_start.x) * (l1_start.y - l2_start.y)) / h;
  float t2 = ((l1_start.y - l1_end.y) * (l1_start.x - l2_start.x) + (l1_end.x - l1_start.x) * (l1_start.y - l2_start.y)) / h;
  struct vec res = {t1, t2};
  return res;
}


bool overlapP(struct polygon poly1, struct polygon poly2)
{

  /* trace("overlapP start"); */
  
  struct polygon p1;
  struct polygon p2;

  for (int direction = 0; direction < 2; ++direction) {
    
    if (direction == 0)
      {
        p1 = poly1;
        p2 = poly2;
      }
    else
      {
        p1 = poly2;
        p2 = poly1;
      }

    
    for (size_t i1 = 0; i1 < p1.length; ++i1) {
      struct vec line1_start = applyTransform(p1.center, p1.scale, p1.angle, p1.pos);
      struct vec line1_end = applyTransform(p1.points[i1], p1.scale, p1.angle, p1.pos);

      /* tracef("line1_start %f %f", line1_start.x, line1_start.y); */
      /* tracef("line1_end %f %f", line1_end.x, line1_end.y); */

      for (size_t i2 = 0; i2 < p2.length; ++i2) {
        struct vec line2_start = applyTransform(p2.points[i2], p2.scale, p2.angle, p2.pos);
        struct vec line2_end = applyTransform(p2.points[(i2+1) % p2.length], p2.scale, p2.angle, p2.pos);
        struct vec res = findIntersect(line1_start, line1_end, line2_start, line2_end);
        /* tracef("========================\n" */
        /*        "line1_start %f %f\n" */
        /*        "line1_end %f %f\n" */
        /*        "line2_start %f %f\n" */
        /*        "line2_end %f %f\n" */
        /*        "res %f %f\n" */
        /*        "i1 %d i2 %d\n" */
        /*        "direction %d\n", */
        /*        line1_start.x, line1_start.y, */
        /*        line1_end.x, line1_end.y, */
        /*        line2_start.x, line2_start.y, */
        /*        line2_end.x, line2_end.y, */
        /*        res.x, res.y, */
        /*        (int)i1, (int)i2, */
        /*        direction */
        /*        ); */
        if (res.x >= 0.0f && res.x < 1.0f && res.y >= 0.0f && res.y < 1.0f)
          {
            return true;
          }
      }
    }

  }

  /* trace("overlapP end"); */
  return false;
}

void collide(struct polygon* poly1, struct polygon* poly2)
{

  struct polygon p1;
  struct polygon p2;

  for (int direction = 0; direction < 2; ++direction) {
    
    if (direction == 0)
      {
        p1 = *poly1;
        p2 = *poly2;
      }
    else
      {
        p1 = *poly2;
        p2 = *poly1;
      }

    
    for (size_t i1 = 0; i1 < p1.length; ++i1) {
      struct vec line1_start = applyTransform(p1.center, p1.scale, p1.angle, p1.pos);
      struct vec line1_end = applyTransform(p1.points[i1], p1.scale, p1.angle, p1.pos);

      struct vec displacement = { 0,0 };

      for (size_t i2 = 0; i2 < p2.length; ++i2) {
        struct vec line2_start = applyTransform(p2.points[i2], p2.scale, p2.angle, p2.pos);
        struct vec line2_end = applyTransform(p2.points[(i2+1) % p2.length], p2.scale, p2.angle, p2.pos);
        struct vec res = findIntersect(line1_start, line1_end, line2_start, line2_end);
        if (res.x >= 0.0f && res.x < 1.0f && res.y >= 0.0f && res.y < 1.0f)
          {
						displacement.x += (1.0f - res.x) * (line1_end.x - line1_start.x);
						displacement.y += (1.0f - res.x) * (line1_end.y - line1_start.y);

            /* trace("======"); */
            /* tracef("line1_start %f %f", line1_start.x, line1_start.y); */
            /* tracef("line1_end %f %f", line1_end.x, line1_end.y); */
            /* tracef("line2_start %f %f", line2_start.x, line2_start.y); */
            /* tracef("line2_end %f %f", line2_end.x, line2_end.y); */
            /* tracef("motion vect %f %f", (line1_end.x - line1_start.x), (line1_end.y - line1_start.y)); */
            /* tracef("res %f %f", res.x, res.y); */
            /* tracef("displacement %f %f", displacement.x, displacement.y); */
          }
      }

      poly1->pos.x += displacement.x * (direction == 0 ? -1 : +1);
      poly1->pos.y += displacement.y * (direction == 0 ? -1 : +1);
    }

  }
}

