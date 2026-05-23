//Check if a string contains only digits.
//Find a word inside a sentence.
//Find how many times a character appears.

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

int main() {
  
  //------------ Check if a string contains only digits. ----------- 
  std::cout << "\nCheck if a string contains only digits.\n";
  std::string x;
  std::cout << "Enter x : ";
  std::cin >> x;
  
  bool onlyDigit = true;
  
  for (int i = 0; i < x.length(); i++) {
    if (x[i] < '0' || x[i] > '9') {
      onlyDigit = false;
      break;
    }
  }
  
  std::cout << (onlyDigit ? "only digit." : "not only digit.") << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
  
  // ------------ Find a word inside a sentence. -------------------
  // -------- Find how many times a character appears. ------------
  
  std::cout << "\nFind how many times a character appears.\n";
  std::cout << "Find a word inside a sentence.\n";
  int word_counter = 0;
  std::string a, word;
  std::cout << "\nEnter a (Sentence) : ";
  getline(std::cin, a);
  std::stringstream ss(a);
  
  std::string b;
  std::cout << "Enter a word to search : ";
  std::cin >> b;
  
  int ch_counter = 0;
  char c;
  std::cout << "Enter a character to count : ";
  std::cin >> c;
  
  bool found = false;
  
  while(ss >> word) {
    if(word == b) {
      found = true;
      std::cout << "\nThe word " << b << " is in the sentence.\n";
      std::cout << "The word is at index : " << word_counter << std::endl;
      break;
    }
    word_counter++;
  }
  
  for(int i = 0; i < a.length(); i++) {
    if(a[i] == c) ch_counter++;
  }
  
  if(!found) {
    std::cout << "The word " << b << " is NOT in the sentence.\n";   
  }
  
  std::cout << "\nThe character " << c << " appeared " << ch_counter << " times in the sentence.\n";
  
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  return 0;
}