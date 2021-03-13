#ifndef _HELLO_POINT_H
#define _HELLO_POINT_H

typedef struct Point Point;

struct Point {
    float X;
    float Y;

    char  * (*String)(Point *);
    float (*Dist)(Point *, Point *);
};

char *Point_String(Point *self);

float Point_Dist(Point *self, Point *other);

// Constructor
Point *NewPoint(float x, float y);

#endif
