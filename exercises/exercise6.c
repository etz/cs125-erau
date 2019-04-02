#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 128



int main () {
    char* name = "Embry Riddle Aeronautical University";
    int i = 0;
    int count = 0;
    /*Declare an array with 128-count size*/
    char Buffer[BUFFER_SIZE] = "";
    char Buffer2[BUFFER_SIZE] = "";
    char Buffer3[BUFFER_SIZE] = "";
    /*One count at a time, with a space between letters*/
    for (i = 0; name[i] != '\0' ; i++) {
        printf("%c ", name[i]);

    }
    printf("\n");
    /*One count at a time, with a newline between letters*/
    for (i = 0; name[i] != '\0' ; i++) {
        if (name[i] == ' ') {
            printf("\n");
            i += 1;
        }
        printf("%c", name[i]);

    }
    /*Search for r or R*/
    
    for (i = 0; name[i] != '\0' ; i++) {
        if(name[i] == 'R' || name[i] == 'r')
            count += 1;
        
    }
    printf("\n%d r's are found in this statement.\n", count);
    
    /*transfer the source string to the destination string*/
    i = 0;
    do {
        Buffer[i] = name[i];
        i++;
    } while(name[i] != '\0');
    printf("Destination String: \n%s\n", Buffer);
    /*transfer the source string to the destination string with a maximum size*/
    
    for (i = 20; i > 0; i--) {
        Buffer2[20-i] = name[20-i];
    }
    Buffer2[19] = '\0';
    printf("\n20 character string: \n%s\n\n", Buffer2);
    /*transfer the source string to the destination string with a maximum size*/
    for (i = 20; i > 0; i--) {
        Buffer3[20-i] = name[i];
    }
    Buffer3[20] = '\0';
    printf("Reverse 20-character string: \n%s\n\n", Buffer3);
}