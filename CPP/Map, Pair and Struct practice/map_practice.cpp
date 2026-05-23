// mapping practice with string (with no uppercase)

#include <iostream>
#include <map>
#include <string>
#include <cctype>  // for tolower

int main() {
  std::string s;
  std::cout << "Enter a string: ";
  std::getline(std::cin, s);
  
  std::map<char, int> freq;
  
  for (char ch : s) {
    if (ch == ' ') {
      continue;  // Ignore spaces
    }
    char lower = std::tolower(ch);
    freq[lower]++;
  }
  
  // Print in alphabetical order (map is already sorted by key)
  for (const auto& pair : freq) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
  
  return 0;
}