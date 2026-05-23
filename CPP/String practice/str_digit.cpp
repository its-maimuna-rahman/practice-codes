// Extract the digits from a sentence and add them.

#include <iostream>
#include <string>
#include <vector>

int main() {
  int sum = 0;
  std::string line;
  std::vector<int> digits;
  std::cout << "Enter sentence : \n";
  getline(std::cin, line);
  
  for(char c : line) {
    if(c >= '0' && c <= '9') {
      digits.push_back(c - '0');
    }
  }
  
  for(int d : digits) {
    sum += d;
  }
  
  std::cout << "The extracted digits are : \n";
  for (int d : digits) {
    std::cout << d << " ";
  }
  std::cout << "\nThe sum of the digits are : " << sum << std::endl; 
  
  return 0;
}  