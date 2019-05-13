/*
 * File:    IntegerSet.h
 * Project: Assignment 12
 * Author:  Michael Van Hilst
 * Version: 2.1 April 13, 2018 Made isetAddArray array argument const.
 *
 * Copyright (c) 2017,2018,2019 Michael Van Hilst all rights reserved
 * Distribution without written permission of the author is prohibited
 */
#ifndef INTEGER_SET_H
#define INTEGER_SET_H

typedef struct {
    int *data;
    int dataCapacity;
    int dataLength;
} IntegerSet;

/* from assignment 11 - unchanged except struct type */
void isetPrint(const IntegerSet *iset, int columns);
void isetClear(IntegerSet *iset);
int isetIndex(const IntegerSet *iset, int value);
int isetRemoveFast(IntegerSet *iset, int index);
int isetRemoveStable(IntegerSet *iset, int index);
int isetAddArray(IntegerSet *iset, const int array[], int arrayLength);

/* for assignment 12 new behaviors */
int isetAdd(IntegerSet *iset, int value);
int isetCopy(const IntegerSet *source, IntegerSet *copy);

/* for assignment 12 new memory management */
int isetInit(IntegerSet *iset, int size);
void isetFree(IntegerSet *iset);
int isetResize(IntegerSet *iset, int size);

/* for assignment 12 extra credit */
IntegerSet* isetCreate(int size);
IntegerSet* isetClone(const IntegerSet *iset);
IntegerSet* isetDestroy(IntegerSet *iset);

/* for assignment 13 coming */
int isetAdd(IntegerSet *iset, int value);
int isetIndexFast(const IntegerSet *iset, int value);

#endif /* INTEGER_SET_H */
