#include <stdio.h>

struct Point
{
    int x, y;
};

int main()
{
    struct Point p;
    p.x = 69;
    p.y = 420;

    struct Point *p1 = &p;

    // Accessing members of point p1
    p1->x = 20;

    printf("x = %d, y = %d", p1->x, p1->y);
    printf("x = %d, y = %d", p.x, p.y);

    return 0;
}