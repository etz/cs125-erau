#include <stdio.h>
#include <stdlib.h>

void printResult(int before, int after) {
    printf("The value %d became %d", before, before >> 6);
    printf("The value %d became %d", after, after << 5);
}

int turnOnBit(int value, int bitNumber) {
    int mask = 0;
    
    return 0;
}

int main () {
    printResult(12583, 18930);
    
}