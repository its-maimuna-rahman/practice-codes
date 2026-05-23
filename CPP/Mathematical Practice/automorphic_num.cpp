// Automorphic number : 5^2 = 25 (ends with 5) (76)^2 = 5776 (ends with 76)

#include <iostream>
#include <cmath>

int main() {
  int n, m, temp1, digit = 0, power = 1;
  
  std::cout << "Enter n = ";
  std::cin >> n;
  
  m = n*n;
  temp1 = n;
  
  while(temp1 != 0) {
    temp1 = temp1 / 10;
    digit++;
  }
  
  for(int i = 0; i < digit; i++) {
    power *= 10;
  }
  
  int tempx = m % power;
  
  if(tempx == n) std::cout << "Automorphic number.\n";
  else               std::cout << "Not an automorphic number.\n";
  
  return 0;
}