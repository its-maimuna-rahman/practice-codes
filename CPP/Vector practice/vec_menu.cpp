//Create a menu: Insert element, Delete element, Display vector, Sort vector, Exit

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, choice, n1, n2, temp;
  std::cout << "\nEnter the number of elements : ";
  std::cin >> n;
  
  std::vector<int> v(n);
  std::cout << "Enter elements\n";
  for(int i = 0; i < n; i++) {
    std::cin >> v.at(i);
  }
  
  while(true) {
    
    std::cout << "\n\n\n===================== MENU =====================\n";
    std::cout << "1. Insert element\n";
    std::cout << "2. Delete element\n";
    std::cout << "3. Display vector\n";
    std::cout << "4. Sort vector\n";
    std::cout << "5. Exit\n";
    
    std::cout << "Enter your choice (1-5) : ";
    std::cin >> choice;
    
    
    
    switch(choice) {
    
    case 1 : 
      std::cout << "\n======= 1. Insert element =======\n";
      std::cout << "How many elements you want to insert? ";
      std::cin >> n1;
      
      for(int i = 0; i < n1; i++) {
        std::cin >> temp;
        v.push_back(temp);
      }
      break;
      
    case 2 :
      std::cout << "\n======= 2. Delete element =======\n";
      std::cout << "How many elements you want to delete (from back)? ";
      std::cin >> n2;
      
      for(int i = 0; i < n2; i++) {
        v.pop_back();
      }
      break;
      
    case 3 :
      std::cout << "\n======= 3. Display Vector =======\n";
      
      for(int i : v) {
        std::cout << i << " ";
      }
      break;
      
    case 4 :        
      std::cout << "\n======= 4. Sort Vector =======\n";
      sort(v.begin(), v.end());
      std::cout << "The vector has been sorted.\n";
      break;
      
    case 5 :
      std::cout << "\n***EXIT*** \n";
      return 0;
      
    default : 
      std::cout << "Invalid input.\n";
    break;
    }
  }
  
  return 0;
}