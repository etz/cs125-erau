/*
 * File:    hw14.c
 * Project: Homework 14
 * Purpose: test driver for student homework
 * Author:  Michael Van Hilst
 * Version: 1.0 November 29, 2017
 *          1.1 April 8, 2019 Removed use of isetCreate and isetClone 
 *
 * Copyright 2017 (c) Michael Van Hilst All rights reserverd.
 */
#include <stdio.h>      /* for printf() */
#include <stdlib.h>     /* for rand() and RAND_MAX */
#include <sys/time.h>   /* for struct timeval and gettimeofday() */
#include "IntegerSet.h" /* homework project header file */

static int fillRandom(int array[], int arrLen, int lowerBound, int upperBound);
static int myrand(void);
#define MYRAND_MAX 32768
static void printTimeDiff(struct timeval *first, struct timeval *second);

/* DATASZ is set to exceed size of array in the IntegerBuffer */
#define DATASZ 48
#define BIGSZ 1000
#define NUMTESTS 8
int main(void) {
    int i = 0;
    int index1 = 0;
    int testIndex[8];
    int testValue[8] = { 3840, 4995, -24, 77, 4000, 309, 2050, 4539 };
    IntegerSet iset;
    IntegerSet copy;
    struct timeval startTime;
    struct timeval finishTime;
    int data[DATASZ];
    int bigData[BIGSZ];
    /* test that isetCreate is working correctly */
    printf("Phase 1: test that isetInit is working correctly\n");
    isetInit(&iset, 35);
    printf("capacity: %d, length: %d\n", iset.dataCapacity, iset.dataLength);
    /* test that isetAdd is working correctly */
    printf("Phase 2: test that isetAdd is working correctly\n");
    isetAdd(&iset, 5);
    isetAdd(&iset, 17);
    isetAdd(&iset, 2);
    isetPrint(&iset, 10);
    /* test that isetAddArray is working correctly */
    printf("Phase 3: test that isetAddArray is working correctly\n");
    fillRandom(data, DATASZ, 20, 50);
    isetAddArray(&iset, data, DATASZ);
    isetPrint(&iset, 10);
    /* test that isetAdd is working with negative numbers */
    printf("Phase 4: test that isetAdd is working with negative numbers\n");
    fillRandom(data, 20, -25, -5);
    isetAddArray(&iset, data, 20);
    isetPrint(&iset, 10);
    /* test that isetClear is working correctly */
    printf("Phase 5: test that isetClear is working correctly\n");
    isetClear(&iset);
    for (i = 0; i < 5; i++)
        isetAdd(&iset, i);
    for (i = 5; i > 0; i--)
        isetAdd(&iset, i);
    isetPrint(&iset, 10);
    /* test that isetIndex, isetRIndex, and isetRemove work correctly */
    printf("Phase 6: test that isetIndex & isetRemoveStable work correctly\n");
    isetRemoveStable(&iset, isetIndex(&iset, 2));
    isetRemoveStable(&iset, isetIndex(&iset, 4));
    isetRemoveStable(&iset, isetIndex(&iset, 0));
    isetRemoveStable(&iset, isetIndex(&iset, 5));
    isetPrint(&iset, 10);
    /* test that isetResize is working */
    printf("Phase 7: test that isetResize is working\n");
    isetResize(&iset, 1024);
    isetPrint(&iset, 10);
    /* test that isetResize is working correctly */
    printf("Phase 8: test that isetResize is working correctly\n");
    fillRandom(bigData, BIGSZ, 20, 5000);
    isetAddArray(&iset, bigData, BIGSZ);
    isetPrint(&iset, 10);
    /* test that isetIndex and isetIndexFast are working correctly */
    printf("Phase 9 (slow):\n");
    gettimeofday(&startTime, 0);
    for (i = 0; i < NUMTESTS; i++)
        testIndex[i] = isetIndex(&iset, testValue[i]);
    gettimeofday(&finishTime, 0);
    for (i = 0; i < NUMTESTS; i++) {
        if (testIndex[i] < 0)
            printf("  %d not found\n", testValue[i]);
        else
            printf("  %d found at: %d (is %d)\n", testValue[i],
                   testIndex[i], iset.data[testIndex[i]]);
    }
    printf("Total search time was ");
    printTimeDiff(&startTime, &finishTime);
#ifdef FAST
    printf("Phase 10 (fast):\n");
    gettimeofday(&startTime, 0);
    for (i = 0; i < NUMTESTS; i++)
        testIndex[i] = isetIndexFast(&iset, testValue[i]);
    gettimeofday(&finishTime, 0);
    for (i = 0; i < NUMTESTS; i++) {
        if (testIndex[i] < 0)
            printf("  %d not found\n", testValue[i]);
        else
            printf("  %d found at: %d (is %d)\n",
                   testValue[i], testIndex[i], iset.data[testIndex[i]]);
    }
    printf("Total search time was ");
    printTimeDiff(&startTime, &finishTime);
#endif
    isetFree(&iset);
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
static int fillRandom(int array[], int arrLen, int lowerBound, int upperBound) {
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
    return((unsigned)(next/65536) % MYRAND_MAX);
}

/* Function: printTimeDiff
 * Purpose:  print the difference in milliseconds between the two timeval structs
 * Argument: start    - timeval captured just before the timed event
 * Argument: stop     - timeval captured just after the time event
 * Returns:  nothing
 * Precondition: both pointers point to valid timeval structs
 * Precondition: both timevals were set by a UNIX gettimeofday function.
 */
void printTimeDiff(struct timeval *start, struct timeval *stop)
{
    double diff = (double)stop->tv_usec - start->tv_usec;
    diff += (stop->tv_sec - start->tv_sec) * 1000000.0;
    printf("%8.0lf milliseconds\n", diff);
}

