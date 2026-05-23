//Reverse a string.
//Check if a string is a palindrome.
//Count words in a sentence.

#include <iostream>
int main() {
  int len, word = 1;
  std::string s1, s2;
  std::cout << "Enter string : ";
  getline(std::cin, s1);
  
  len = s1.length();
  s2.resize(len);
  
  for(int i = 0; i < len; i++) {
    s2[i] = s1[len-1-i];
  }
  std::cout << "\nReversed string : " << s2;
  
  if(s2 == s1) std::cout << "\nIt is a palindrome\n";
  else std::cout << "\nIt is NOT a palindrome\n";
  
  for(int i = 0; i < len; i++) {
    if(s1[i] == ' ') word++;
  }
  
  std::cout << "words = " << word;
  
  return 0;
}  