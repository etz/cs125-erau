/*
 * File:    hw12.c
 * Project: Homework 12
 * Purpose: test driver for student homework
 * Author:  Michael Van Hilst
 * Version: 2.1 April 18, 2018
 *          3.0 April 4, 2019 Major revisions
 *
 * Copyright 2017, 2019 (c) Michael Van Hilst All rights reserverd.
 */
#include <stdio.h>      /* for printf() */
#include <stdlib.h>     /* for NULL, EXIT_SUCCESS */
#include "IntegerSet.h" /* homework project header file */

static int fillRandom(int array[], int arrLen, int lowerBound, int upperBound);
static int myrand(void);
#define MYRAND_MAX 32768

/* DATASZ is set to exceed size of array in the IntegerBuffer */
#define DATASZ 48
int main(void) {
    int i = 0;
    int index = 0;
    int tempSize = 0;
    int tempLength = 0;
    IntegerSet iset1;
    IntegerSet iset2;
    IntegerSet *iset3 = NULL;
    int data[DATASZ];
    /* test that isetInit is working correctly */
    printf("Phase 1: Testing isetCreate()\n");
    isetInit(&iset1, 35);
    isetInit(&iset2, 20);
    printf("  set1 size: %d, length: %d\n",
       iset1.dataCapacity, iset1.dataLength);
    printf("  set2 size: %d, length: %d\n",
       iset2.dataCapacity, iset2.dataLength);
    /* test that isetAdd is working correctly */
    printf("Phase 2: Testing isetAdd()\n");
    isetAdd(&iset1, 5);
    isetAdd(&iset1, 17);
    isetAdd(&iset1, 2);
    isetAdd(&iset1, 5);
    isetAdd(&iset1, 2);
    isetAdd(&iset1, 3);
    isetPrint(&iset1, 10);
    /* test that isetAddArray is working correctly */
    printf("Phase 3: Testing isetAddArray()\n");
    printf("  fillRandom returned %d\n", fillRandom(data, DATASZ, 20, 50));
    isetAddArray(&iset1, data, DATASZ);
    isetPrint(&iset1, 10);
    printf("Phase 3: Testing isetAddArray() on set2\n");
    isetAddArray(&iset2, data, 30);
    isetPrint(&iset2, 10);
    printf("  set1 size: %d, length: %d\n",
       iset1.dataCapacity, iset1.dataLength);
    printf("  set2 size: %d, length: %d\n",
       iset2.dataCapacity, iset2.dataLength);
    /* test that isetCopy is working correctly */
    printf("Phase 4: Testing isetCopy() to set2\n");
    isetCopy(&iset1, &iset2);
    isetPrint(&iset2, 10);
    /* test that isetClear is working correctly */
    printf("Phase 5: Testing isetClear()\n");
    isetClear(&iset1); 
    printf("  set1 size: %d, length: %d\n",
       iset1.dataCapacity, iset1.dataLength);
    for (i = 0; i < 5; i++)
        isetAdd(&iset1, i);
    for (i = 9; i > 0; i--)
        isetAdd(&iset1, i);
    isetPrint(&iset1, 10);
    /* test that resize works correctly */
    printf("Phase 6: Testing isetResize()\n");
    tempSize = iset2.dataCapacity;
    tempLength = iset2.dataLength;
    isetPrint(&iset2, 10);
    printf("  attempting to add this data (with duplicates) from an array:\n");
    printf("  %d", data[0]);
    for (i = 1; i < 16; i++)
        printf(", %d", data[i]);
    printf("\n");
    printf("  set2 size: %d, length: %d\n",
       iset2.dataCapacity, iset2.dataLength);
    isetResize(&iset2, 30);
    printf("  set2 size: %d, length: %d\n",
       iset2.dataCapacity, iset2.dataLength);
    tempSize = iset2.dataCapacity;
    tempLength = iset2.dataLength;
    isetPrint(&iset2, 10);
    /* test that isetIndex and isetRemove work correctly */
    printf("Phase 7: testing isetIndex() and isetRemove()\n");
    index = isetIndex(&iset1, 2);
    isetRemoveFast(&iset1, index);
    isetRemoveStable(&iset1, isetIndex(&iset1, 4));
    isetPrint(&iset1, 10);
    /* test that isetClone works correctly */
    printf("Phase 8: testing isetClone()\n");
    iset3 = isetClone(&iset2);
    isetPrint(iset3, 10);
    printf("  set3 size: %d, length: %d\n",
       iset3->dataCapacity, iset3->dataLength);
    isetFree(&iset1);
    isetFree(&iset2);
    iset3 = isetDestroy(iset3);
    return EXIT_SUCCESS;
}

/* Function: fillRandom
 * Purpose:  fill an integer array with random values in a given range
 * Argument: array      - an array of integers
 * Argument: arrLen     - the number of integers to generate
 * Argument: lowerBound - the lowest value that could be generated
 * Argument: upperBound - the highest value that could be generated
 * Returns:  nothing
 * Precondition: array points to a valid array of ints
 * Precondition: arrLen is not greater than the available space in array
 */
static int fillRandom(int array[], int arrLen, int lowerBound, int upperBound) {
    int i = 0;
    /* static makes this a persistent variable
       that is initialized only once */
    static int notSeeded = 1;
    double range = 1.0 + upperBound - lowerBound;
    if (notSeeded) {
        /* if we want it seeded, the srand goes here */
        notSeeded = 0;
    }
    for (i = 0; i < arrLen; i++) {
        /* refactored the order to force doubles to be used w/o cast */
        array[i] = (int)(myrand() * (range / MYRAND_MAX) + lowerBound);
    }
    return i;
}

/* POSIX.1-2001 gives the following example of an implementation of rand(),
 * useful when one needs the same sequence on different machines.
 */
static int myrand(void) {
    static unsigned long next = 1;
    next = next * 1103515245 + 12345;
    return((unsigned)(next / 65536) % MYRAND_MAX);
}

