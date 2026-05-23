// replace a particular word from a sentence
#include <iostream>
#include <string>

int main() {
  std::string text, old_word, new_word, word;
  std::cout << "\nEnter the Sentence : \n";
  getline(std::cin, text);
  
  std::cout << "\nEnter the word you wanna replace : ";
  std::cin >> old_word;
  
  std::cout << "\nEnter the new word : ";
  std::cin >> new_word;
  
  size_t pos = 0;

  while((pos = text.find(old_word, pos)) != std::string::npos) {
    text.replace(pos, old_word.length(), new_word);
    pos += new_word.length();
  }
  
  std::cout << "\nUpdated sentence:\n" << text << std::endl;
  
  return 0;
}  