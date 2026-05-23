// even odd separation, find miximum.
#include <iostream>
#include <string>
#include <vector>

int main() {
  int n;
  std::cout << "enter n = ";
  std::cin >> n;
  std::vector<int> num(n);
  std::vector<int> even(0);
  std::vector<int> odd(0);
  
  for(int i = 0; i < num.size(); i++) {
    std::cout << "Enter num " << i+1 << " : ";
    std::cin >> num.at(i);
  }
  
  for(int n : num) {
    if(n % 2 == 0) {
      even.push_back(n);
    }
    else {
      odd.push_back(n);
    }
  }
  
  std::cout << "\nvector of even numbers :\n";
  std::cout << "size : " << even.size() << std::endl;
  for(int n : even) {
    std::cout << n << " ";
  }
  
  std::cout << "\n\nvector of odd numbers :\n";
  std::cout << "size : " << odd.size() << std::endl;
  for(int n : odd) {
    std::cout << n << " ";
  }
  
  int max = 0;
  for(int n : num) {
    if(n > max) {
      max = n;
    }
  }
  std::cout << "\n\nHighest number : " << max << std::endl;
  
  return 0;
}