//Compress string (aaabbc --- > a3b2c1).

#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cout << "s = ";
  std::cin >> s;
  
  for(int i = 0; i < s.length(); i++) {
    int count = 1;
    
    if(s[i] == s[i+1]) {
      while(i + 1 < s.length() && s[i] == s[i+1]) {
        count++;
        i++;
      }
    }
    
    std::cout << s[i] << count;
  }
  
  return 0;
}
