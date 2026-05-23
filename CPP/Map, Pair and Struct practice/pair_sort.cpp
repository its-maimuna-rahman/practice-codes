//Input n pairs (x, y).
//Sort by: Ascending x, Descending y if x is same

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, x, y;
  cout << "\nEnter number of pairs: ";
  cin >> n;
  
  vector<pair<int, int>> v;
  cout << "Enter elements: (x, y)\n";
  for (int i = 0; i < n; i++) {
    cout << "Enter pair " << i+1 << " : ";
    cin >> x >> y;
    v.push_back({x, y});
  }
  
  cout << "\nThe paired vector : \n";
  for(const auto &p : v) {
    cout << "(" << p.first << ", " << p.second << ")" << " ";
  }
  
  sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first != b.first) {
      return a.first < b.first;
    }
    
    return a.second > b.second;
  });
  
  cout << "\n\nThe sorted paired vector : \n";
  for(const auto &p : v) {
    cout << "(" << p.first << ", " << p.second << ")" << " ";
  }
  
  return 0;
} 
