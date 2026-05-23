//Strong Number - A number where sum of factorials of digits equals the number
 
#include <iostream>

int factorial(int n) {
  int s = 1;
  for(int i = 1; i <= n; i++) {
    s *= i;
  }
  return s;
}

int main() {
  int n, temp1, temp2, digit = 0, str = 0;
  
  std::cout << "Enter n = ";
  std::cin >> n;
  
  temp1 = n;
  temp2 = n;
  
  while(temp1 != 0) {
    temp1 = temp1 / 10;
    digit++;
  }
  
  for(int i = 0; i < digit ; i++) {
    int temp3 = temp2 % 10;
    str += factorial(temp3); 
    temp2 = temp2 / 10;
  }
  
  if(str == n) std::cout << "Strong number\n";
  else         std::cout << "Not a strong number.\n";
  
  
  return 0;
}