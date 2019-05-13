#include <stdio.h>
#include <stdlib.h>


void printXYZ(int v1, int v2, int v3){
    printf("x: %d\n", v1);
    printf("y: %d\n", v2);
    printf("z: %d\n", v3);
}


void enterXYZ(int *prtX, int *prtY, int *prtZ){
    printf("Enter three values:");
    while (scanf( "%d, %d, %d", prtX, prtY, prtZ) != 3) {
        printf("There was an issue entering those integers. Try again.");
    }
}
void swap(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void xyzAscending(int *px, int *py, int *pz){
    if (*pz > *py){
        swap(pz, py);
    }
    if (*py > *px){
        swap(py, px);
    }
    if (*pz > *py) {
        swap(pz, py);
    }
}


int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    printXYZ(x,y,z);
    enterXYZ(&x, &y, &z);
    printXYZ(x,y,z);
    xyzAscending(&x, &y, &z);
    printXYZ(x,y,z);
}
