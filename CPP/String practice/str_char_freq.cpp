//Find the most frequent character of a sentence.

#include <iostream>
#include <string>

int main() {
  std::string sent; 
  std::cout << "Enter sentence = ";
  getline(std::cin, sent);
  
  int freq1[256] = {0};
  
  for(char c1 : sent) {
    if(c1 != ' ') {
      freq1[c1]++;
    }
  }
  
  int max_count = 0;
  char max_char;
  
  for(int i = 0; i < 256; i++) {
    if(freq1[i] > max_count) {
      max_count = freq1[i];
      max_char = i;
    } 
  }
  
  std::cout << "\nMost frequent character: " << max_char << std::endl;
  std::cout << "Frequency: " << max_count << std::endl;
  std::cout << std::endl;
  
  int freq2[256] = {0};
  
  for(char c2 : sent) {
    if(c2 != ' ')
      freq2[(unsigned char)c2]++;
  }
  
  std::cout << "Frequency by each alphabet : \n";
  for(int i = 0; i < 256; i++) {
    if(freq2[i] != 0)
      std::cout << (char)i << "  " << freq2[i] << std::endl;
  }
  
  return 0;
}