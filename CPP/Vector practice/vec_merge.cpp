// Merging 2 vectors and sorting it without sort function
#include <iostream>
#include <string>
#include <vector>

int main() {
  int in1, in2;
  std::vector<int> merge;
  
  std::cout << "\nEnter number of elements of v1 : ";
  std::cin >> in1;
  std::vector<int> v1(in1);
  
  std::cout << "\nEnter v1 elements : \n";
  for(int i = 0; i < v1.size(); i++) {
    std::cin >> v1.at(i);
    merge.push_back(v1.at(i));
  }
  
  std::cout << "\nEnter number of elements of v2 : ";
  std::cin >> in2;
  std::vector<int> v2(in2);
  
  std::cout << "\nEnter v2 elements : \n";
  for(int j = 0; j < v2.size(); j++) {
    std::cin >> v2.at(j);
    merge.push_back(v2.at(j));
  }
  
  // bubble sort in merge vector
  for(int i = 0; i < merge.size() - 1; i++) {
    for(int j = 0; j < merge.size() - i - 1; j++) {
      if(merge[j] > merge[j+1]) {
        int temp = merge[j];
        merge[j] = merge[j+1];
        merge[j+1] = temp;
      }
    }
  }
  
  std::cout << "\nMerged and sorted vector : \n";
  for(int i : merge) {
    std::cout << i << " ";
  }
  
  return 0;
}