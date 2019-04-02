#include <stdio.h>
#include <stdlib.h>

int num = 0;

double getRandomNumber(num) {
  num = rand() * 10;
  return num;

}

int main() {
  getRandomNumber();
  printf("%d", num); 
  getRandomNumber();
  printf("%d", num);
  getRandomNumber();
  printf("%d", num);
}

