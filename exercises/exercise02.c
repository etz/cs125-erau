#include <stdio.h> 

/*Stores Int*/
int c = 0;

/*Stores Check*/
int f = 0;

int getUserInteger(c, f) {
    int d = 0;
    /*Check if int*/
    printf("\nEnter an integer:");
    c = scanf("%d", &f);
    /*Check if valid*/
        if (c != 0) {
            printf("Your returned integer is: %d", f);
        } else {
            printf("\nYou have entered a bad input.");
            d = scanf("%d", &f);
            getUserInteger(d, f);
        }
}

int printSum(f,c) {
    /*Sum*/
    int s = f + c;
    printf("The SUM of %d + %d = %d", f, c, s);
}

int main() {
    getUserInteger();
}
