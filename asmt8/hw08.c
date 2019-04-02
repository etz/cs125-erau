/*
 * File:    hw08.c
 * Project: Homework 8 fileIO in CS125
 * Author:  Thomas Nadzieja
 * Version: 1.0 March 7th, 2019
 *
 * Copyright (c) your name 2019 All rights reserverd
 */
#include <stdio.h>
#include <stdlib.h>

/* Functions needed for part 1 of assignment 8 - writing to a file */
int fillRandom(double array[], int length,
	       double lowerLimit, double upperLimit);
void writeArray(FILE* fp, const double array[], int length);
void writeToFile(const char* fileName, const double arrray[], int length);
void part1(void);
/* Additional functions for part 2 of assignment 8 - reading from a file */
int readArray(FILE* fp, double array[], int maxCount);
int readFromFile(const char* filename, double array[], int size);
void part2(void);

int main(void) {
    part1();
    part2();
    return EXIT_SUCCESS;
}

#define ARRAY_SIZE 100
void part1(void) {
    double array[ARRAY_SIZE];
    int arrayLength = 0;
    arrayLength = fillRandom(array, ARRAY_SIZE, 10, 75);
    writeToFile( "data1.txt", array, arrayLength);
    arrayLength = fillRandom(array, 13, 130.2, 130.7);
    writeToFile( "data2.txt", array, arrayLength);
}


#define BIG_BUFFER_SZ 1024
#define SMALL_BUFFER_SZ 48
void part2(void) {
    double buffer1[BIG_BUFFER_SZ];
    double buffer2[BIG_BUFFER_SZ];
    double buffer3[SMALL_BUFFER_SZ];
    int buffer1Len = 0;
    int buffer2Len = 0;
    int buffer3Len = 0;
    fputs("data1.txt\n", stdout);
    buffer1Len = readFromFile("data1.txt", buffer1, BIG_BUFFER_SZ);
    writeArray(stdout, buffer1, buffer1Len);
    fputs("data2.txt\n", stdout);
    buffer2Len = readFromFile("data2.txt", buffer2, BIG_BUFFER_SZ);
    writeArray(stdout, buffer2, buffer2Len);
    fputs("data3.txt\n", stdout);
    buffer3Len = readFromFile("data3.txt", buffer3, SMALL_BUFFER_SZ);
    writeArray(stdout, buffer3, buffer3Len);
    fputs("data1.txt\n", stdout);
    buffer3Len = readFromFile("data1.txt", buffer3, SMALL_BUFFER_SZ);
    writeArray(stdout, buffer3, buffer3Len);
}

/* implement your 5 functions here */

/* use rand() to get a random double in given range */
double randomBetween(double lowerLimit, double upperLimit) {
    double range = upperLimit - lowerLimit;
    return (rand() / (RAND_MAX + 1.0)) * range + lowerLimit;
}

int fillRandom(double array[], int length, double lowerLimit, double upperLimit) {
    int i;
    for (i = 0; i < length; i++) {
        array[i] = randomBetween(lowerLimit, upperLimit);
    }
}

void writeToFile(const char* fileName, const double array[], int length) {
    int c;
    FILE* fp = fopen(fileName, "w");
    c = fputs("Start of data \n", fp);
    writeArray(fp, array, length);
    c = fputc('\n', fp);
    c = fputs("End of data", fp);
    fclose(fp);
}


void writeArray(FILE* fp, const double array[], int length){
    int i;
    int c;
    for (i = 0; i < length; i++) {
        if (i % 10 == 0) {
            c = fputs("\n", fp);
        }
        fprintf(fp, "%7.2f", array[i]);
    }
    putc('\n', stdout);
}

int readFromFile(const char* filename, double array[], int size){
    int c;
    FILE* fp = fopen(filename, "r");
    if (fp) {
        return readArray(fp, array, size);
    } else {
        perror(filename);
        putc('\n', stdout);
        return 0;
    }
}

int readArray(FILE* fp, double array[], int maxCount){
    int i;
    fscanf(fp, "%*[^0-9]");
    for (i = 0; i < maxCount && fscanf(fp, "%lf", &(array[i])); i++){
    }
    return i;
}

