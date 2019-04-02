/*
*  File: asmt05_nadzieja.c
*  Project: hw05
*  Author: Thomas Ethan Nadzieja
*  Description: Demonstrates the logic of a slot machine
*  Version: 1.0 Februrary 5th, 2019
*  Copyright Thomas Ethan Nadzieja 2019
*/

#include <stdio.h>
#include <stdlib.h>

/* Function: findHex
* Purpose: finds the hex code of each character
* Argument: char* input - character being translated
* Returns: string
* Precondition: N/A
* Postcondition:  N/A
*/
void findHex(char letter) {
    printf("%x hex, ", letter);
}

/* Function: findDec
* Purpose: finds the decimal value of each character
* Argument: char* input - character being translated
* Returns: int
* Precondition: N/A
* Postcondition:  N/A
*/
void findDec(char letter) {
    printf("%d decimal, ", letter);
}

/* Function: findBin
* Purpose: finds the binary value of each character
* Argument: char* input - character being translated
* Returns: int
* Precondition: N/A
* Postcondition:  throw value to findBits
*/

int findBin(char letter) {
    int mask = 128;
    int i = 8;
    int decimal = ("%d", letter);
    while (i > 0) {
        if ((decimal & mask) == mask) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
        i--;
    }
    return 0;
}

/* Function: findBits
* Purpose: finds the bit set of each character
* Argument: char* input - character being translated
* Returns: int
* Precondition: requires Binary to be found
* Postcondition:
*/

int findBits(char letter) {
    int bits = 0;
    int mask = 128;
    int i = 8;
    int decimal = ("%d", letter);
    while (i > 0) {
        if ((decimal & mask) == mask) {
            bits += 1;
        }
        mask >>= 1;
        i--;
    }
    printf("%d", bits);
    findPar(bits);
}

/* Function: findPar
* Purpose: finds the parity of each character
* Argument: char* input - character being translated
* Returns: string
* Precondition:
* Postcondition:done
*/

int findPar(int bits) {
    printf(" bits are set, parity is ");
    if (bits % 2 == 0) {
        printf("even");
        return;
    }
    printf("odd");
}

/* Function: analyzeChar
* Purpose: Completes the function for each letter
* Argument: char* input - character being translated
* Returns: printf statement
* Precondition: input from user
* Postcondition: string output
*/

void analyzeChar(char input) {
    if (input == '\n') {
        printf("The ASCII code for \'\\n\' is");
    } else {
        printf("The ASCII code for \'%c\' is", input);
    }
    findHex(input);
    findDec(input);
    findBin(input);
    printf(" as binary, ");
    findBits(input);
    printf("\n");
}



int main() {
    char c;
    printf("Please type a string: ");
    do {
        scanf("%c", & c);
        analyzeChar(c);
    } while (c != '\n');
    return 0;
}