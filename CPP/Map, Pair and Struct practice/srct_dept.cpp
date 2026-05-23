// Input students with department.
//Group students by department.
//Print department-wise list.

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
#include <limits>

struct student {
  int roll;
  std::string name;
  std::string department;
};

void add_student(std::vector<student> &v){
  student s;
  
  while(1) {
    std::cout << "roll :  ";
    std::cin >> s.roll;
    
    if(s.roll >= 0) {
      break;
    }
    else {
      std::cout << "Invalid input. roll must be positive integer.\n";
      continue;
    }  
  }
  
  while(1) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "name : ";
    getline(std::cin, s.name);
    
    bool hasDigit1 = false;
    for(char c : s.name) {
      if(isdigit(static_cast<unsigned char>(c))) {
        std::cout << "Invalid input. Name can not contain digits.\n";
        hasDigit1 = true;
        break;  
      }
    }
    
    if(!hasDigit1 && !s.name.empty()) {
      break;
    }
  }
  
  while(1) {
    
    std::cout << "department : ";
    getline(std::cin, s.department);
    
    bool hasDigit2 = false;
    for(char c : s.department) {
      if(isdigit(static_cast<unsigned char>(c))) {
        std::cout << "Invalid input. department can not contain digits.\n";
        hasDigit2 = true;
        break;  
      }
    }
    
    if(!hasDigit2 && !s.department.empty()) {
      break;
    }
  }
  
  v.push_back(s);
  
}

void print(const std::vector<student> &v) {
  std::cout << "\n---------------- STUDENT LIST ----------------\n";
  
  std::cout << "roll" << "  \t"
            << "name" << "  \t"
            << "department" << std::endl;
  
  std::cout << "----------------------------------------------\n";
  for(const student &x : v) {
    std::cout << x.roll << "  \t"
         << x.name << "  \t"
         << x.department << std::endl;
  }
  
}

int main() {
  int n;
  while(1) {
    std::cout << "Enter number of students : ";
    std::cin >> n;
    
    if(n > 0) {
      break;
    }
    else {
      std::cout << "Invalid input. number of students must be positive integer.\n";
      continue;
    }  
  }
  
  std::vector<student> std; 
  for(int i = 0; i < n; i++) {
    std::cout << "Enter student " << i+1 << "'s info : \n";
    add_student(std);
  }
  print(std);
  
  std::map<std::string, std::vector<student>> deptmap;
  
  for(const auto& s : std) {
    deptmap[s.department].push_back(s);
  }
  
  for(const auto& dept : deptmap) {
    std::cout << "\nDepartmant :\n\n" << dept.first << std::endl;
    
    for(const auto& s : dept.second) {
      std::cout << "Roll : " << s.roll << ",\tName : " << s.name << std::endl;
    }
  }
  
    return 0;
}