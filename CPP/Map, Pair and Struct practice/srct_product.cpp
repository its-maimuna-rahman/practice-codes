//Input product name, category, and price.
//Group products by category and print with prices.

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
#include <limits>

struct product {
  std::string name;
  std::string category;
  double price;
};

void input(std::vector<product> &v) {
  product p;
  
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Enter product NAME : ";
  getline(std::cin, p.name);
  
  std::cout << "Enter product CATEGORY : ";
  getline(std::cin, p.category);
  
  while(1) {
    std::cout << "Enter product PRICE : ";
    std::cin >> p.price;
    
    if(p.price > 0) {
      break;
    }
    else {
      std::cout << "Invalid input for price.\n";
      continue;
    }
  }
  
  v.push_back(p);
}

void print(std::vector<product> &v) {
  std::cout << "\n=================== PRODUCT INFO ===================\n";
  std::cout << "NAME\t|\tCATEGORY|\tPRICE\n"; 
  for(const auto& x : v) {
    std::cout << x.name << "\t|\t"
              << x.category << "\t|\t"
              << x.price << "|\n";
  }
  
}

int main() {
  int n;
  while(1) {
    std::cout << "Enter Number of products : ";
    std::cin >> n;
    
    if(n > 0) {
      break;
    }
    else {
      std::cout << "Invalid input.\n";
      continue;
    }
  }
  std::cout << std::endl;
  
  std::vector<product> vec;
  for(int i = 0; i < n; i++) {
    std::cout << "\nEnter info for product " << i+1 << " : \n";
    input(vec);
  }
  print(vec);
  
  std::map<std::string, std::vector<product>> cat_map;
  for(const auto& x : vec) {
    cat_map[x.category].push_back(x);
  }
  
  std::cout << "\n========= PRODUCT DISTRIBUTION BY CATEGORY =========\n\n";
  for(const auto& y : cat_map) {
    std::cout << std::endl;
    std::cout << "category : " << y.first << std::endl;
    
    for(const auto& z : y.second) {
      std::cout << "\tname : " << z.name << "\tprice : " << z.price << std::endl;
    }
  }
  
  return 0;
}
