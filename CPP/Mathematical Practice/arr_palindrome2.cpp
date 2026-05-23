// check if an array is a palindrome or not
#include <iostream>

int main() {
  int n;
  
  std::cout << "Array size, n (odd) = ";
  std::cin >> n;
  while(1) {
    if(n % 2 == 0) {
      std::cout << "n needs to be odd.\n";
      std::cout << "Array size, n (odd) = ";
      std::cin >> n;
    }
    else break;
  }
  
  int a1[n], a2[n] = {0};
  
  std::cout << "Enter the array's elements : \n";
  for(int i = 0; i < n; i++) {
    std::cin >> a1[i];
  }
  
  std::cout << "The original array : \n";
  for(int i = 0; i < n; i++) {
    std::cout << a1[i] << " ";
  }
  
  int j = 0;
  for(int i = n-1; i >= 0; i--) {
    a2[j] = a1[i];
    j++;
  }
  
  std::cout << "\nThe reversed array : \n";
  for(int i = 0; i < n; i++) {
    std::cout << a2[i] << " ";
  }
  
  for(int i = 0; i < n; i++) {
    if(a2[i] != a1[i]) {
      std::cout << "\nThis array is not Palindrome.\n";
      return 0;
    }
  }
  std::cout << "\nThis array is Palindrome.\n";
  
  return 0;
}  
