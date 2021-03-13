#ifndef _HELLO_POINT_C
#define _HELLO_POINT_C

#include "gc.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> 


char *Point_String(Point *self) {
    char *string = GC_MALLOC(sizeof(char *));
    sprintf(string, "x:%f y:%f", self->X, self->Y);
    return string;
}


float Point_Dist(Point *self, Point *other) {
    return (self->X - other->X) + (self->Y - other->Y);
}


Point *NewPoint(float x, float y) {
    Point *p = GC_MALLOC(sizeof(Point)); 
    p->X = x;
    p->Y = y;
    p->String = Point_String;
    p->Dist = Point_Dist;
    return p;
}

#endif
