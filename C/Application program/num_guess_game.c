#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i = 0;
  int number, guess;
  srand(time(NULL));
  number = rand() % 1000 +1;      // random number generator (1-1000)
  
  printf("====== Number Guessing Game ======\n");
  
  while( i < 10) {
    printf("Enter your guess (1-1000) : ");
    scanf("%d", &guess);
    
    if(guess < 1 || guess > 1000) {
      printf("Invalid choice.\n");
      continue;
    }
    
    if(guess == number) {
      printf("Excellent. You've guessed the number : %d\n", guess);
      return 0;
    }
    else if(guess < number) {
      printf("Too low. Guess higher.\n");
    }
    else if(guess > number) {
      printf("Too high. Guess lower.\n");
    }
    i++;
  }
  
  printf("10 times is over. you lost.\n");
  printf("The number was %d\n", number);
  
  return 0;
}