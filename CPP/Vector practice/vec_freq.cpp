// frequency count of a vector's elements, by map libary

#include <iostream>
#include <vector>
#include <map>

int main() {
  int n;
  std::cout << "\nEnter number of elements: ";
  std::cin >> n;
  
  std::vector<int> v(n);
  
  std::cout << "Enter elements:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  
  std::cout << "\nThe vector :\n";
  for(int i = 0; i < n; i++) {
    std::cout << v[i] << " "; 
  }
  
  std::map<int, int > freq;
  
  for(int x : v) {
    freq[x]++;
  }
  
  std::cout << "\n\nThe frequency : \n\n";
  std::cout << "Element   --> Frequency\n";
  std::cout << "-----------------------\n";
  for(auto x : freq) {
    std::cout << "  " << x.first << "       -->      " << x.second << std::endl;
  }
  
  return 0;   
}