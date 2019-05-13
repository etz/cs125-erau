#include <stdio.h>
#include <stdlib.h>
#include "IntegerSet.h"

static int recursiveSearch(const int array[], int value,int low, int high);

int isetInit(IntegerSet *iset, int bufferSize) {
    iset->data = malloc( bufferSize * sizeof(int) );
    if (iset->data != NULL){
        iset->dataLength = 0;
        iset->dataCapacity = bufferSize;
        return 1;
    } else {
        iset->dataLength = 0;
        iset->dataCapacity = 0;
        return 0;
    }
    
    
}

void isetClear(IntegerSet *iset) {
    
    int i;
    for (i = 0; i < iset->dataLength; i++) {
        iset->data[i] = '\0';
    }
    iset->dataLength = 0;
}

int isetAdd(IntegerSet *iset, int value){
    
    int i = 0;
    int j = 0;
    if(iset->dataLength < iset->dataCapacity && isetIndex(iset, value) == -1){
        for (i = 0; i < iset->dataLength && iset->data[i] < value; i++);
        iset->dataLength++;
        for(j = (iset->dataLength - 1); j>= i; j--){
            iset->data[j + 1] = iset->data[j];
        }
        iset->data[i] = value;
        return 1;
    }
    return 0;
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
    isetRemoveStable(iset,index);
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
    if (iset->data != NULL){
        free(iset->data);
        iset->dataCapacity = 0;
        iset->dataLength = 0;
        iset->data = NULL;
    }
}


int isetResize(IntegerSet *iset, int size) {
    int *tempPtr;
    tempPtr = realloc(iset->data, size * sizeof(int));
    if (tempPtr != NULL){
        iset->dataCapacity = size;
        if (iset->dataLength > size)
            iset->dataLength = size;
        iset->data = tempPtr;
        return 1;
    } else
        return 0;
    return 0;
    
}


IntegerSet* isetClone(const IntegerSet *iset){}
IntegerSet* isetDestroy(IntegerSet *iset){}


/*int isetIndexFast(const IntegerSet *iset, int value) {
    return recursiveSearch(iset->data, value, 0, iset->dataLength–1);

}*/
