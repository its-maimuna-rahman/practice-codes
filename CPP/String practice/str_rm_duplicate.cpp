// remove duplicate

#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cout << "Enter string : ";
  std::cin >> s;
  
  bool seen[256] = {false};      // ASCII table
  std::string result = "";
  
  for(char c : s) {
    if(!seen[(unsigned char)c]) {
      seen[(unsigned char)c] = true;
      result += c;
    }
  }
  
  std::cout << "\nThe string after removing duplicates : \n"
            << result << std::endl;
  
  return 0;
}