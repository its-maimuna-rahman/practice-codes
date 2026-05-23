// checking if 2 vector are anagrams or not. (elements and their frequencies
//are same reargdless of order)

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n;
  cout << "\nEnter number of elements: ";
  cin >> n;
  
  vector<int> v1(n);
  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++) {
    cin >> v1[i];
  }
  
  vector<int> v2(n);
  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++) {
    cin >> v2[i];
  }
  
  cout << "\nThe vector 1 :\n";
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  
  cout << "\nThe vector 2 :\n";
  for (int x : v2) {
    cout << x << " ";
  }
  cout << endl;
  
  map<int, int> freq1;
  for(auto& i : v1) {
    freq1[i]++;
  }
  
  map<int, int> freq2;
  for(auto& i : v2) {
    freq2[i]++;
  }
  
  if(freq1 == freq2) {
    cout << "\nThe vectors are equal.\n";
  }
  else {
    cout << "\nThe vectors are NOT equal.\n";
  }
  
  return 0;
} 

