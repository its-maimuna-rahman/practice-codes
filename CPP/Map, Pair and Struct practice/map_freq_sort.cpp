// order the vector's elements by the descending order of their frequency

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cout << "\nEnter number of elements: ";
  cin >> n;
  
  vector<int> v(n);
  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  cout << "\nThe vector:\n";
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  
  // Step 1: Count frequency
  map<int, int> freq;
  for (int num : v) {          // Fixed: proper range-based loop
    freq[num]++;
  }
  
  // Step 2: Create a vector of pairs (value, frequency) for sorting
  vector<pair<int, int>> vec;
  for (auto& p : freq) {
    vec.push_back({p.first, p.second});  // {value, frequency}
  }
  
  // Step 3: Sort by frequency descending, then by value ascending if tie
  sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) {
      return a.second > b.second;    // Higher frequency first
    }
    return a.first < b.first;        // If same frequency, smaller value first
  });
  
  // Step 4: Print elements repeated by their frequency (or just unique sorted)
  cout << "\nElements sorted by frequency (descending):\n";
  for (auto& p : vec) {
    for (int i = 0; i < p.second; i++) {
      cout << p.first << " ";
    }
  }
  cout << endl;
  
  return 0;
}