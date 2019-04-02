#include<stdio.h>

int step4()
{
  int check = 1;
  int value = 0;
  printf("Please enter an integer between 1-20: ");
  check = scanf("%d", &value);
  if(check != 0){
    if(value > 0 && value < 20){
      if(value == 8 || value == 11 || value == 18){
        printf("You entered an %d", value);
        } else {
            printf("You entered a %d", value);
          }
      } else {
          printf("The number you entered was not between 1-20");
    }
  } else {
    printf("Idiot! Your input could not be read as a number. Get a life!");
  }
}

int step3()
{
  int value = 0;
  printf("Please enter an integer between 1-20: ");
  scanf("%d", &value);
  if(value > 0 && value < 20){
    if(value == 8 || value == 11 || value == 18){
      printf("You entered an %d", value);
      } else {
          printf("You entered a %d", value);
        }
    } else {
        printf("The number you entered was not between 1-20");
  }
}

int step2()
{
  int value = 0;
  printf("Please enter an integer between 1-20: ");
  scanf("%d", &value);
  if(value > 0 && value < 20){
    printf("You entered a %d", value);
  } else {
    printf("The number you entered was not between 1-20");
  }
}

int step1()
{
  int value = 0;
  printf("Please enter an integer between 1-20: ");
  scanf("%d", &value);
  printf("You entered a %d", value);
}

int main()
{
  step1();
  step2();
  step3();
  step4();
  return 0;
}

