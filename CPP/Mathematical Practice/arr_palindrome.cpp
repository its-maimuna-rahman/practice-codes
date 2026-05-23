// check if an array is a palindrome or not

#include <iostream>

int main() {
  int n;
  
  std::cout << "Array size, n = ";
  std::cin >> n;
  
  int a1[n], a2[n/2] = {0}, a3[n/2] = {0};
  
  std::cout << "Enter the array's elements : \n";
  for(int i = 0; i < n; i++) {
    std::cin >> a1[i];
  }
  
  std::cout << "The original array : \n";
  for(int i = 0; i < n; i++) {
    std::cout << a1[i] << " ";
  }
  
  for(int i = 0; i < n/2; i++) {
    a2[i] = a1[i];
  }
  
  int j = 0;
  for(int i = n-1; i >= n/2; i--) {
    a3[j] = a1[i];
    j++;
  }
  
  std::cout << "\nThe a2 array : \n";
  for(int i = 0; i < n/2; i++) {
    std::cout << a2[i] << " ";
  }
  std::cout << "\nThe a3 array : \n";
  for(int i = 0; i < n/2; i++) {
    std::cout << a3[i] << " ";
  }
  
  for(int i = 0; i < n/2; i++) {
    if(a2[i] != a3[i]) {
      std::cout << "\nThis array is not Palindrome.\n";
      return 0;
    }
  }
  std::cout << "\nThis array is Palindrome.\n";

  return 0;
}  
  