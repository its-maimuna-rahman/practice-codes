// Check if 2 words are anagrams or not
//An anagram is a word or phrase formed by rearranging the letters of another
//word or phrase, using all the original letters exactly once.
//example : dusty --> study

#include <iostream>

int main() {
  std::string word1, word2; 
  
  std::cout << "Enter word 1 = ";
  std::cin >> word1;
  std::cout << "Enter word 2 = ";
  std::cin >> word2;
  
  int freq1[256] = {0};
  int freq2[256] = {0};
  
  for(char c1 : word1) {
    freq1[c1]++;
  }
  for(char c2 : word2) {
    freq2[c2]++;
  }
  
  for(int i = 0; i < 256; i++) {
    if(freq1[i] != freq2[i]) {
      std::cout << word1 << " and " << word2 << " are NOT anagrams.\n";
      return 0;
    }
  }
  std::cout << word1 << " and " << word2 << " are anagrams.\n";
  
  return 0;
}