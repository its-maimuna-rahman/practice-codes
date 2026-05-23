// find pair with Maximum Difference
//step 1 : input a vector of integers.
//step 2 : Store (value, index) using pair
//step 3 : Find pair (i, j) such that j > i and v[j] - v[i] is maximum
//step 4 : Print the pair

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
  int n, temp;
  cout << "Enter n : ";
  cin >> n;
  
  // step 1
  vector<int> v(n);
  cout << "Enter the elements : \n";
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }    
  
  // step 2
  vector<pair<int, int>> v2;
  for(int i = 0; i < n; i++) {
    v2.push_back({v.at(i), i});
  }
  cout << "\nPair with index {element, index}\n";
  for(auto& x : v2) {
    cout << "(" << x.first << ", " << x.second << ")" << " ";
  }
  
  // step 3
  int max_diff = -1, curr_diff;
  pair<int, int> best_pair;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      curr_diff = v[j] - v[i];
      if(curr_diff > max_diff) {
        max_diff = curr_diff;
        best_pair = {v[i], v[j]};
      }
      
    }
  }
  
  // step 4
  if(max_diff == -1) {
    cout << "\n\nNo pair found with positive difference.\n";
  } else {
    cout << "\n\nPair of elements with maximum difference {element, element}: (" 
         << best_pair.first << ", " << best_pair.second << ")\n";
    cout << "Maximum difference: " << max_diff << endl;
  }
  
  return 0;
}