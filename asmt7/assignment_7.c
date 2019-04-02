#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* use rand() to get a random double in given range */
double randomBetween(double lowerLimit, double upperLimit);
/* assign random doubles to array elements */
int fillRandom(double *array, int numberToFill, double lowerLimit, double upperLimit);
/* print the array values one above the other */
void listTheArrayValues(double* array, int arrayLength);
/* return the minimum value found in the array */
double minOfArrayValues(double* array, int arrayLength);
/* return the maximum value found in the array */
double maxOfArrayValues(double* array, int arrayLength);
/* return the sum of the values in the array */
double sumOfArrayValues(double* array, int arrayLength);
/* return the mean of the array, using sumOfArrayValues() to get the sum */
double meanOfArrayValues(double* array, int arrayLength);
/* return variance of the array, use meanOfArrayValues() to get the mean */
double populationVariance(double* array, int arrayLength);
/* return standard deviation, using sqrt() and varianceOfArrayValues */
double populationStandardDeviation(double* array, int arrayLength);
#define ARRAY_SIZE 100
#define DATA_LENGTH 75
int main(void) {
    double myArray[ARRAY_SIZE];
    int lengthFilled = fillRandom(myArray, DATA_LENGTH, 40.0, 60.0);
    listTheArrayValues(myArray, lengthFilled);
    printf("The sum of the %d values was %.3f\n", lengthFilled,
           sumOfArrayValues(myArray, lengthFilled));
    printf("The smallest was %.3f, and the largest was %.3f\n",
           minOfArrayValues(myArray, lengthFilled),
           maxOfArrayValues(myArray, lengthFilled));
    printf("The average of the values was %.3f\n",
           meanOfArrayValues(myArray, lengthFilled));
    printf("The population standard deviation was %.3f\n",
           populationStandardDeviation(myArray, lengthFilled));
    return 0;
}

/* use rand() to get a random double in given range */
double randomBetween(double lowerLimit, double upperLimit) {
    double range = upperLimit - lowerLimit;
    return (rand() / (RAND_MAX + 1.0)) * range + lowerLimit;
}

/* assign random doubles to array elements */
int fillRandom(double *array, int numberToFill, double lowerLimit, double upperLimit) {
    int i;
    for (i = 0; i < numberToFill; i++) {
        array[i] = randomBetween(lowerLimit, upperLimit);
    }
}
/* print the array values one above the other */
void listTheArrayValues(double* array, int arrayLength) {
    int i;
    int counter = 0;
    for (i = 0; i < arrayLength; i++) {
        printf("number[%d] is %.3f\n", counter, array[i]);
        counter ++;
    }
}

/* return the minimum value found in the array */
double minOfArrayValues(double* array, int arrayLength) {
    int count = 0;
    double min = array[0];
    do {
        if (array[count] < min)
            min = array[count];
        count++;
    } while (count < arrayLength);
    return (double)min;
}
/* return the maximum value found in the array */
double maxOfArrayValues(double* array, int arrayLength) {
    int count = 0;
    double max = array[0];
    do {
        if (array[count] > max)
            max = array[count];
        count++;
    } while (count < arrayLength);
    return (double)max;
}
/* return the sum of the values in the array */
double sumOfArrayValues(double* array, int arrayLength) {
    int i;
    double sum = 0;
    for (i = 0; i < arrayLength; i++) {
        sum += array[i];
    }
    return sum;
}
/* return the mean of the array, using sumOfArrayValues() to get the sum */
double meanOfArrayValues(double* array, int arrayLength) {
    double sum = sumOfArrayValues (array, arrayLength);
    double mean = (sum / ((double)arrayLength));
    return mean;
}
/* return variance of the array, use meanOfArrayValues() to get the mean */
double populationVariance(double* array, int arrayLength) {
    
    double variance;
    double sumOfMean = 0;
    double mean = meanOfArrayValues(array, arrayLength);
    int i;
    for (i = 0; i < arrayLength; i++) {
        sumOfMean += pow((array[i] - mean), 2);
    }
    variance = (sumOfMean / ((double)arrayLength));
    return variance;
    
}

double populationStandardDeviation(double* array, int arrayLength) {
    
    double variance = populationVariance(array, arrayLength);
    double deviation = pow(variance, .5);
    return deviation;
    
}
