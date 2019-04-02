#include<stdio.h>
int main()
{
  int input = 0;
  int integers = 0;
  int positive = 0;
  int negative = 0;
  int quit = 1;
  do {
    int lock = 0;
    printf("Please enter an integer: ");
    quit = scanf("%d", &lock);
    if (quit != 0){
      if(lock > 0){
        positive = positive + 1;
        } else if (lock < 0){
            negative = negative + 1;
        }
        input += lock;
        integers = integers + 1;
      }
    }
  while (quit >= 1);
  printf("\nYou entered %d integers", integers);
  printf("\n%d of the integers were negative", negative);
  printf("\n%d of the integers were positive", positive);
  printf("\nThe sum of the %d integers was %d", integers, input);
}

