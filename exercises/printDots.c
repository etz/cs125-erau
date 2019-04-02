#include <stdio.h>

int gotCount(char* promptIn) {
    int input = 0;
    printf("%s", promptIn);
    scanf("%d", &input);
    return input;
}

int printDashes(int numberOfDashes) {
    int count2 = 0;
    for (count2 = 0; numberOfDashes >= count2; count2++) {
        printf("-");
    }
}

int printDots(int numberOfDots) {
    int count = 0;
    while(numberOfDots >= count) {
        printf(".");
        count++;
    }
}


int main() {    
    printDots(gotCount("Enter how many dots:"));
    printf("\n");
    printDashes(gotCount("Enter how many dashes:"));

}