#include <stdio.h>
#include "IntegerBuffer.h"

void ibufInit(IntegerBuffer *ibuf) {
    
    ibuf->dataLength = 0;
    ibuf->dataCapacity = sizeof(ibuf->data) / sizeof(ibuf->data[0]);
    
}

void ibufClear(IntegerBuffer *ibuf) {
    
    int i;
    for (i = 0; i < ibuf->dataLength; i++) {
        ibuf->data[i] = 0;
    }
    ibuf->dataLength = 0;
}


int ibufAdd(IntegerBuffer *ibuf, int value) {
    
    if (ibuf->dataLength < ibuf->dataCapacity) {
        ibuf->dataLength ++;
        ibuf->data[ibuf->dataLength - 1] = value;
        return 1;
    }
    else {
        return 0;
    }
}

int ibufIndex(const IntegerBuffer *ibuf, int value) {
    
    int x;
    for (x = 0; x < ibuf->dataLength; x++) {
        if (ibuf->data[x] == value) {
            return x;
        }
    }
    return -1;
}

int ibufAddArray(IntegerBuffer *ibuf, const int array[], int arrLen) {
    
    int x;
    int c;
    for (x = 0; x < arrLen; x++) {
        ibufAdd(ibuf, array[x]);
        c++;
    }
    return c;
}

int ibufRemoveFast(IntegerBuffer *ibuf, int index) {
    
    if (index < 0 || index >= ibuf->dataLength) {
        return 0;
    }
    else {
        int value = ibuf->data[ibuf->dataLength - 1];
        ibuf->data[index] = value;
        value = 0;
        ibuf->dataLength --;
        return 1;
    }
}

int ibufRemoveStable(IntegerBuffer *ibuf, int index) {
    
    if (index < 0 || index >= ibuf->dataLength) {
        return 0;
    }
    else {
        int x;
        ibuf->data[index] =  0;
        for (x = (index + 1); x < ibuf->dataLength; x++) {
            ibuf->data[x - 1] = ibuf->data[x];
        }
        ibuf->dataLength --;
        return 1;
    }
}

void ibufPrint(const IntegerBuffer *ibuf, int numberOfColumns) {
    int i = 0;
    for (i = 0; i < ibuf->dataLength; i++) {
        if (i % numberOfColumns== 0 && i != 0)
            fputc('\n', stdout);
        printf("%6d", ibuf->data[i]);
    }
    fputc('\n', stdout);
}

