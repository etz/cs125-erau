#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
 double x;
 double y;
} Point;

typedef struct {
 Point angle0;
 Point angle1;
 Point angle2;
} Triangle;

Point enterPoint();
void printVertices(const Triangle *tr);
double distanceBetweenPoints(const Point *p1, const Point *p2);
double getPerimeter(const Triangle* tr);


int main() {
    Triangle T;
    T.angle0 = enterPoint();
    T.angle1 = enterPoint();
    T.angle2 = enterPoint();
    printVertices(&T);
    printf ("The perimeter is %.2f", getPerimeter(&T));
}

Point enterPoint() {
    printf ("Enter the x and y coordinates separated by a comma: ");
    Point randpoint;
    scanf ("%lf,", &randpoint.x);
    scanf ("%lf", &randpoint.y);
    return randpoint;
}

void printVertices(const Triangle *tr) {
    printf ("The point coordinates are: ");
    printf ("[%.2f, %.2f], ", tr->angle0.x, tr->angle0.y);
    printf ("[%.2f, %.2f], ", tr->angle1.x, tr->angle1.y);
    printf ("and [%.2f, %.2f]\n", tr->angle2.x, tr->angle2.y);
}

double distanceBetweenPoints(const Point *p1, const Point *p2) {
    double x = (p2->x - p1->x);
    double y = (p2->y - p1->y);
    double distance = sqrt((x*x)+(y*y));
    return distance;
}

double getPerimeter(const Triangle* tr) {
    double a, b, c;
    a = distanceBetweenPoints(&tr->angle0, &tr->angle1);
    b = distanceBetweenPoints(&tr->angle1, &tr->angle2);
    c = distanceBetweenPoints(&tr->angle2, &tr->angle0);
    double perimeter = a + b + c;
    return perimeter;
}
