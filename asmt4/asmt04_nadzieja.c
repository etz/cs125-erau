/*
 *  File: asmt04_nadzieja.c
 *  Project: hw04
 *  Author: Thomas Ethan Nadzieja
 *  Description: Demonstrates the logic of a slot machine
 *  Version: 1.0 Februrary 1st, 2019
 *  Copyright Thomas Ethan Nadzieja 2019
*/

#include <stdio.h>
#include <stdlib.h>

/* Function: randomBetween
 * Purpose: find an integer between two numbers
 * Argument: smallestInteger - the low end of range
 * Argument: largestInteger – the high end of range
 * Returns: random integer
 * Precondition: determined range
 * Postcondition: N/A
 */

int randomBetween (int smallestInteger, int largestInteger) {
    double range = 1.0 + largestInteger - smallestInteger;
    double normalizedRand = rand() / (RAND_MAX + 1.0);
    return (int)(normalizedRand * range + smallestInteger);
}

/* Function: printImageName
 * Purpose: returns a character to the slot machines console
 * Argument: slot - returns the value of the slot
 * Returns: char
 * Precondition: randomBetween() and playGame()
 * Postcondition: N/A
 */

printImageName(int slot) {
    if (slot == 1) {
        return '#';
    } else if (slot == 2) {
        return '$';
    } else if (slot == 3) {
        return '@';
    } else {
        return '+';
    }
}

/* Function: printLosingGame
 * Purpose: returns a slot turn which did not win
 * Argument: slot1, slot2, slot3 - values of the slots
 * Returns: console log
 * Precondition: playGame()
 * Postcondition: N/A
 */

printLosingGame(int slot1, int slot2, int slot3) {
    printf("| %c ", printImageName(slot1));
    printf("|| %c ", printImageName(slot2));
    printf("|| %c |", printImageName(slot3));
}

/* Function: printWinningGame
 * Purpose: returns a slot turn which did win
 * Argument: slot1, slot2, slot3 - values of the slots
 * Returns: console log
 * Precondition: playGame()
 * Postcondition: N/A
 */

printWinningGame(int slot1, int slot2, int slot3) {
    printf("| %c ", printImageName(slot1));
    printf("|| %c ", printImageName(slot2));
    printf("|| %c |", printImageName(slot3));
    printf("  You win!");
}

/* Function: playGame
 * Purpose: begins the process of creating a slot turn
 * Returns: console log
 * Precondition: Requires user to press enter
 * Postcondition: Returns printWinningGame() or printLosingGame()
 */

playGame() {
    int slot1 = randomBetween(1, 4);
    int slot2 = randomBetween(1, 4);
    int slot3 = randomBetween(1, 4);
    if (slot1 == slot2 && slot2 == slot3 && slot1 == slot3) {
        printWinningGame(slot1, slot2, slot3);
    } else {
        printLosingGame(slot1, slot2, slot3);
    }
}

int main () {
    int playing = 1;
    char userInput;
    printf("Press enter to play or q to quit:");
    while (playing == 1) {
    scanf("%c", &userInput);
        if(userInput == 'q') {
            playing = 0;
        } else {
            playGame();
        }
    }
}
