/*
*  File: asmt06_nadzieja.c
*  Project: hw06
*  Author: Thomas Ethan Nadzieja
*  Description: Manipulates strings
*  Version: 1.0 Februrary 8th, 2019
*  Copyright Thomas Ethan Nadzieja 2019
*/

#include <stdio.h>

/* replace all lower case letters with upper case letters */
void stringToUpper(char* str, int maxLength)
{
    int i = 0;
    for (i = 0; i < maxLength && str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i]-32;
    }

}

/* return the number of times letter appears in the string */
int stringCountChar(char letter, char* str, int maxLength)
{
    int count = 0;
    int match = 0;
    do {
        if (str[count] == letter) {
            match++;
        }
        count++;
    } while (str[count] != '\0');
    return match;
}

/* Function: stringLength
 * Argument: str       - the string array
 * Returns:  the length of the string
 * Postcondition: Nothing is changed
 */
int stringLength(char* str)
{
    int length = 0;
    do {
        if (str[length] != '\0') {
            length++;
        }
    } while (str[length] != '\0');
    return length;
}

/* Function: safeStringLength
 * Argument: str       - the string array
 * Argument: maxLength - the size of the array holding the string
 * Returns:  the length of the string
 * Postcondition: If there were no nulls within maxlength,
 *                function puts a null character at [maxLength - 1]
 */
int safeStringLength(char* str, int maxLength)
{
    int length = 0;
    for(maxLength = maxLength; maxLength >= 0; maxLength--){
        if (str[length] != '\0'){
            length++;
        }
    }
    return length;
}

/* Function: stringCopy
 * Purpose:  Copy the string from source to destination (but unsafe)
 * Argument: source          - the string to be copied
 * Argument: destination     - the array into which to copy the string
 * Precondition:  the source is a valid string with null termination
 * Postcondition: the destination has the same string as the source
 */
void stringCopy(char* source, char* destination)
{
    int sloop = 0;
    do {
        destination[sloop] = source[sloop];
        sloop += 1;
    } while(source[sloop] != '\0');
}

/* Function: safeStringCopy
 * Purpose:  Copy the string from source to destination
 * Argument: source          - the string to be copied
 * Argument: destination     - the array into which to copy the string
 * Argument: destinationSize - the size available for destination
 * Precondition:  the source is a valid string with null termination
 * Postcondition: the destination has the same string as the source
 *                but not more than one less than destinationSize
 * Postcondition: if destination array is filled, last element is null 
 */
void safeStringCopy(char* source, char* destination, int destinationSize)
{
    int character = 0;
    for (destinationSize = destinationSize; destinationSize > 0; destinationSize--) {
        destination[character] = source[character];
    }
    destination[destinationSize-1] = '\0';
}

/* Function: replaceChar
 * Purpose:  Replace all instances of old character with new character
 * Argument: old       - the character to be replaced
 * Argument: new       - the new character to replace the old
 * Argument: str       - the string array
 * Argument: maxLength - the size of the array holding the string
 */
void replaceChar(char old, char new, char* str, int maxLength)
{
    int i = 0;
    for (i = 0; i < maxLength && str[i] != '\0'; i++)
        if (str[i] == old)
            str[i] = new;
}

#define BUFFER_SIZE 128
int main(void)
{
    char buffer[BUFFER_SIZE] = "";
    char copy[BUFFER_SIZE] = "";
    char* result = NULL;
    int length = 0;
    int count = 0;
    int i = 0;
    printf("Enter a sentence or other string: ");
    result = fgets(buffer, BUFFER_SIZE, stdin);
    /* make sure there is at least 1 null */
    buffer[BUFFER_SIZE - 1] = '\0';
    /* remove the newline at the end */
    replaceChar('\n', '\0', buffer, BUFFER_SIZE);
    /* print the line that was read */
    printf("%s\n", buffer);
    /* demonstrate that stringLength() works correctly */
    length = stringLength(buffer);
    printf("The length of the string is %d.\n", length);
    length = safeStringLength(buffer, BUFFER_SIZE);
    for (i = 0; i < length; i++)
        printf("-");
    printf("\n");
    /* demonstrate that stringToUpper() works correctly */
    stringToUpper(buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    /* demonstrate that stringCountChar() works correctly */
    count = stringCountChar(buffer[0], buffer, BUFFER_SIZE);
    printf("The letter %c appears %d times.\n", buffer[0], count);
    /* demonstrate that stringCopy works, including length limit */
    stringCopy(buffer, copy);
    printf("%s\n", copy);
    safeStringCopy(buffer, copy, length - 5);
    printf("%s\n", copy);
    return 0;
}
