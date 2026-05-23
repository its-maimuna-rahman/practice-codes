//Move all zeros of an array to end Maintain relative order: 1 0 2 0 -> 1 2 0 0


#include <iostream>

int main() {
  int n, zero_count = 0;
  
  std::cout << "Array size, n = ";
  std::cin >> n;
  
  int a1[n], a2[n], a3[n];
  
  std::cout << "Enter the array's elements : \n";
  for(int i = 0; i < n; i++) {
    std::cin >> a1[i];
  }
  
  std::cout << "The original array : \n";
  for(int i = 0; i < n; i++) {
    std::cout << a1[i] << " ";
  }
  
  for(int i = 0; i < n; i++) {
    if(a1[i] == 0) zero_count++;
   }
   
  int k = 0; 
  for(int i = 0; i < n; i++) {
    if(a1[i] != 0) {
      a2[k] = a1[i];
      k++;
    }
  }  
  
  std::cout << "\n\nTotal zeros : " << zero_count << std::endl;
  
  std::cout << "The array without zero : \n";
  for(int i = 0; i < (n-zero_count); i++) {
    std::cout << a2[i] << " ";
  }
  
  int temp = 0;
  for(int i = 0; i < ((n-zero_count) - 1) ; i++) {
    for(int j = 0; j < ((n-zero_count) - i - 1); j++) {
      if(a2[j] > a2[j+1]) {
        int temp = a2[j];
        a2[j] = a2[j+1];
        a2[j+1] = temp;
      }
    }
  }
  
  for(int i = 0; i < n; i++) {
    if(i < (n-zero_count)) {
      a3[i] = a2[i];
    }
    else{
      a3[i] = 0;
    }
  }
  
  std::cout << "\n\nThe array with relative order : \n";
  for(int i = 0; i < n; i++) {
    std::cout << a3[i] << " ";
  }
  
  return 0;
}