#ifndef INTEGER_BUFFER_H
#define INTEGER_BUFFER_H
/*
 * File:    IntegerBuffer.h
 * Project: Homework 11
 * Purpose: Type declarations for the integer data buffer assignment.
 * Author:  Michael Van Hilst
 * Version: 1.0 November 11, 2017 (in the 11th hour of the 11th day ...)
 *          1.1 July 25, 2018     changed name of buffer array to data
 *          2.0 March 29, 2019    update for 2019
 *
 * Copyright 2017, 2019 (c) Michael Van Hilst All rights reserverd.
 */
typedef struct {
    int dataCapacity;
    int dataLength;
    int data[32];
} IntegerBuffer;

void ibufInit(IntegerBuffer *ibuf);
void ibufClear(IntegerBuffer *ibuf);
void ibufPrint(const IntegerBuffer *ibuf, int numberOfColumns);
int ibufAdd(IntegerBuffer *ibuf, int value);
int ibufAddArray(IntegerBuffer *ibuf, const int array[], int arrayLength);
int ibufIndex(const IntegerBuffer *ibuf, int value);
int ibufRemoveFast(IntegerBuffer *ibuf, int index);
int ibufRemoveStable(IntegerBuffer *ibuf, int index);

#endif /* INTEGER_BUFFER_H */

