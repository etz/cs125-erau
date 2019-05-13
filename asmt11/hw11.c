/*
 * File:    hw11.c
 * Project: Homework 11
 * Purpose: test driver for student homework
 * Author:  Michael Van Hilst
 * Version: 1.0 November 11, 2017 (in the 11th hour of the 11th day ...)
 *          2.0 March 29, 2019 updated with different behavior
 *
 * Copyright 2017,2019 (c) Michael Van Hilst All rights reserverd.
 */
#include <stdio.h>         /* for printf() */
#include "IntegerBuffer.h" /* homework project header file */

void fillRandom(int array[], int arrLen, int lowerBound, int upperBound);
int myrand(void);
#define MYRAND_MAX 32768

/* DATASZ is set to exceed size of array in the IntegerBuffer */
#define DATASZ 48
int main(void) {
    int i = 0;
    int index = 0;
    int result = 0;
    IntegerBuffer ibuf;
    int data[DATASZ];
    /* test that ibufInit is working correctly */
    printf("Phase 1:\n");
    ibufInit(&ibuf);
    printf("size: %d, length: %d\n", ibuf.dataCapacity, ibuf.dataLength);
    /* test that ibufAdd is working correctly */
    printf("Phase 2:\n");
    ibufAdd(&ibuf, 5);
    ibufAdd(&ibuf, 17);
    ibufPrint(&ibuf, 10);
    /* test that ibufAddArray is working correctly */
    printf("Phase 3:\n");
    fillRandom(data, DATASZ, 20,75);
    result = ibufAddArray(&ibuf, data, DATASZ);
    printf("reported adding %d of %d\n", result, DATASZ);
    ibufPrint(&ibuf, 9);
    /* test that ibufClear is working correctly */
    printf("Phase 4:\n");
    ibufClear(&ibuf);
    for (i = 0; i < 5; i++)
        ibufAdd(&ibuf, i);
    for (i = 5; i > 0; i--)
        ibufAdd(&ibuf, i);
    ibufPrint(&ibuf, 10);
    /* test that ibufIndex, ibufRemoveDast and ibufRemoveStable work */
    printf("Phase 5:\n");
    index = ibufIndex(&ibuf, 2);
    ibufRemoveFast(&ibuf, index);
    ibufRemoveStable(&ibuf, ibufIndex(&ibuf, 4));
    ibufPrint(&ibuf, 10);
    /* use the #ifdef NOTYET line to hide parts you haven't yet done */
#ifdef NOTYET
#endif
    return 0;
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
void fillRandom(int array[], int arrLen, int lowerBound, int upperBound) {
    int i;
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
        /* a good optimizer will also recognize that (range / RAND_MAX)
         * can be done outside the loop */
        array[i] = (int)(myrand() * (range / MYRAND_MAX) + lowerBound);
    }
}

/* POSIX.1-2001 gives the following example of an implementation of rand(),
 * useful when one needs the same sequence on different machines.
 */
int myrand(void) {
   static unsigned long next = 1;
   next = next * 1103515245 + 12345;
   return((unsigned)(next/65536) % MYRAND_MAX);
}
