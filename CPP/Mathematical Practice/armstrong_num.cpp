// Checking Armstrong number

#include <iostream>
#include <cmath>

int main() {
  int n, digit = 0, ams = 0;
  
  while(n <= 0) {
    std::cout << "Enter an positive integer = ";
    std::cin >> n;
  }
  
  int temp1 = n;
  int temp2 = n;
  
  while(temp1 != 0) {
    temp1 = temp1 / 10;
    digit++;
  }
  
  for(int i = 0; i < digit ; i++) {
    int temp3 = temp2 % 10;
    ams += pow(temp3, 3); 
    temp2 = temp2 / 10;
  }
  
  if(ams == n) {
    std::cout << "Armstrong number\n";
  }
  else {
    std::cout << "Not an Armstrong number\n"; 
  }
  
  return 0;
}