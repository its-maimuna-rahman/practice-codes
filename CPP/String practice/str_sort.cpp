//Compare two strings lexicographically.
//Sort strings in alphabetical order.
//Find the longest word in a sentence.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
  
  // ---------- 1. Lexicographical comparison ----------
  std::string a, b;
  std::cout << "\nEnter first string: ";
  std::cin >> a;
  std::cout << "Enter second string: ";
  std::cin >> b;
  
  if(a < b) std::cout << a << " comes before " << b << std::endl;
  else if(b < a) std::cout << b << " comes before " << a << std::endl;
  else std::cout << a << " and " << b << " are equal." << std::endl;
  
  std::cin.ignore();
  
  // ---------- 2. Sort strings alphabetically ----------
  int n;
  std::cout << "\n\nHow many words? ";
  std::cin >> n;
  
  std::vector<std::string> words(n);
  
  std::cout << "Enter words:\n";
  for(int i = 0; i < n; i++) {
    std::cin >> words[i];
  }
  
  sort(words.begin(), words.end());
  
  std::cout << "Sorted words:\n";
  for (int i = 0; i < n; i++)
    std::cout << words[i] << " ";
  
  std::cin.ignore();
  
  // ---------- 3. Longest word in a sentence ----------
  std::string sentence;
  std::cout << "\n\nEnter a sentence: ";
  getline(std::cin, sentence);
  
  std::string word, longest;
  std::stringstream ss(sentence);
  
  while(ss >> word) {
    if(word.length() > longest.length())
      longest = word;
  }
  std::cout << "Longest word: " << longest << std::endl;
  
  return 0;
}