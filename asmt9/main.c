#include <stdio.h>
#include <stdlib.h>

typedef struct {
 double x;
 double y;
} Point;

typedef struct {
 Point angle0;
 Point angle1;
 Point angle2;
} Triangle;

Point getRandomPoint();
Point FindCentroid(Triangle T);

int main() {
    Triangle T;
    Point centroidAns;
    T.angle0 = getRandomPoint();
    T.angle1 = getRandomPoint();
    T.angle2 = getRandomPoint();
    printf("The vertices of the angle are ");
    printf ("[%.2f, %.2f], ", T.angle0.x, T.angle0.y);
    printf ("[%.2f, %.2f], ", T.angle1.x, T.angle1.y);
    printf ("and [%.2f, %.2f]", T.angle2.x, T.angle2.y);
    centroidAns = FindCentroid(T);
    printf("\nThe centroid is [%.2f, %.2f]", centroidAns.x, centroidAns.y);
}

Point getRandomPoint() {
    Point randpoint;
    randpoint.x = (rand() / (RAND_MAX + 1.0)) * 1 + 0;
    randpoint.y = (rand() / (RAND_MAX + 1.0)) * 1 + 0;
    return randpoint;
}

Point FindCentroid(Triangle T) {
    Point centroid;
    centroid.x = (T.angle0.x + T.angle1.x + T.angle2.x) / 3;
    centroid.y = (T.angle0.y + T.angle1.y + T.angle2.y) / 3;
    return centroid;
}

