#include <stdio.h>
#include <stdlib.h>
#include "IntegerSet.h"

int isetInit(IntegerSet *iset, int bufferSize) {
    iset->data = malloc( bufferSize * sizeof(int) );
    iset->dataLength = 0;
    iset->dataCapacity = bufferSize;
    
}

void isetClear(IntegerSet *iset) {
    
    int i;
    for (i = 0; i < iset->dataLength; i++) {
        iset->data[i] = 0;
    }
    iset->dataLength = 0;
}


int isetAdd(IntegerSet *iset, int value) {
    
    if (iset->dataLength < iset->dataCapacity && isetIndex(iset, value) == -1) {
        iset->dataLength ++;
        iset->data[iset->dataLength - 1] = value;
        return 1;
    } else {
        return 0;
    }
}

int isetIndex(const IntegerSet *iset, int value) {
    
    int x;
    for (x = 0; x < iset->dataLength; x++) {
        if (iset->data[x] == value) {
            return x;
        }
    }
    return -1;
}

int isetAddArray(IntegerSet *iset, const int array[], int arrLen) {
    int x;
    int c;
    for (x = 0; x < arrLen; x++) {
        isetAdd(iset, array[x]);
        c++;
    }
    return c;
}

int isetRemoveFast(IntegerSet *iset, int index) {
    
    if (index < 0 || index >= iset->dataLength) {
        return 0;
    }
    else {
        int value = iset->data[iset->dataLength - 1];
        iset->data[index] = value;
        value = 0;
        iset->dataLength --;
        return 1;
    }
}

int isetRemoveStable(IntegerSet *iset, int index) {
    
    if (index < 0 || index >= iset->dataLength) {
        return 0;
    }
    else {
        int x;
        iset->data[index] =  0;
        for (x = (index + 1); x < iset->dataLength; x++) {
            iset->data[x - 1] = iset->data[x];
        }
        iset->dataLength --;
        return 1;
    }
}

void isetPrint(const IntegerSet *iset, int numberOfColumns) {
    int i = 0;
    for (i = 0; i < iset->dataLength; i++) {
        if (i % numberOfColumns== 0 && i != 0)
            fputc('\n', stdout);
        printf("%6d", iset->data[i]);
    }
    fputc('\n', stdout);
}

int isetCopy(const IntegerSet *source, IntegerSet *copy){
    isetClear(copy);
    return isetAddArray(copy, source->data, source->dataLength);
}

void isetFree(IntegerSet *iset){
    if (iset->data == NULL){
        iset->dataCapacity = 0;
        iset->dataLength = 0;
        free(iset->data);
        iset->data = NULL;
    }
}

int isetResize(IntegerSet *iset, int size) {
    int *check;
    check = realloc(iset->data, (size * sizeof(int)));
    if (check != NULL){
        iset->dataCapacity = size;
        return 1;
    }
    return 0;
    
}

IntegerSet* isetClone(const IntegerSet *iset){}
IntegerSet* isetDestroy(IntegerSet *iset){}
