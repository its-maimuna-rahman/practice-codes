#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  int number, guess;
  srand(time(NULL));
  number = rand() % 1000 +1;      // random number generator (1-1000)
  
  printf("====== Number Guessing Game ======\n");
  
  for(int i = 0; i < 10; i++) {
    std::cout << "Enter your guess (1-1000) : ";
    std::cin >> guess;
    
    if(guess < 1 || guess > 1000) {
      std::cout << "Invalid choice.\n";
      continue;
    }
    
    if(guess == number) {
      std::cout << "Excellent. You've guessed the number : " <<  guess << std::endl;
      return 0;
    }
    else if(guess < number) {
      std::cout << "Too low. Guess higher.\n";
    }
    else if(guess > number) {
      std::cout << "Too high. Guess lower.\n";
    }
  }
  
  std::cout << "10 times is over. you lost.\n";
  std::cout << "The number was " << number << std::endl;
  
  return 0;
}