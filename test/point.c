#include <assert.h>
#include "../src/hello.c"


void test_point_dist(void) {
    Point *p1 = NewPoint(10, 11);
    Point *p2 = NewPoint(9, 8);
    assert(((void)"distance", p1->Dist(p1, p2) == 4.0));
}

void test_point(void) {
    for (int x = 0; x < 10000; x++) {
        test_point_dist();
    }
}
