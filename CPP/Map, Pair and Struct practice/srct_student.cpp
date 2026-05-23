// Student Ranking System
// 1. Store in vector and print
// 2. Rank students by marks and print
// 3. Handle ties
// 4. Print top 3 students

// be careful about putting roll and marks, if you put string, the program will crash
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

struct student {
  int roll;
  string name;
  float marks;
};


void add_student(vector<student> &v){
  student s;
  
  while(1) {
    cout << "roll :  ";
    cin >> s.roll;
    
    if(s.roll >= 0) {
      break;
    }
    else {
      cout << "Invalid input. roll must be positive integer.\n";
      continue;
    }  
  }
  
  while(1) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "name : ";
    getline(cin, s.name);
    
    bool hasDigit = false;
    for(char c : s.name) {
      if(isdigit(static_cast<unsigned char>(c))) {
        cout << "Invalid input. Name can not contain digits.\n";
        hasDigit = true;
        break;  
      }
    }
    
    if(!hasDigit && !s.name.empty()) {
      break;
    }
  }
  
  while(1) {
    cout << "marks : ";
    cin >> s.marks;
    
    if(s.marks >= 0 && s.marks <= 100) {
      break;
    }
    else {
      cout << "Invalid input. marks must be between 0 and 100.\n";
      continue;
    }   
  }
  
  v.push_back(s);
  
}

void print(const vector<student> &v) {
  cout << "\n---------------- STUDENT LIST ----------------\n";
  
  cout << "roll" << "  \t"
       << "name" << "  \t"
       << "marks" << endl;
  
  cout << "----------------------------------------------\n";
  for(const student &x : v) {
    cout << x.roll << "  \t"
         << x.name << "  \t"
         << x.marks << endl;
  }
  
}

int main() {
  int n;
  while(1) {
    cout << "Enter number of students : ";
    cin >> n;
    
    if(n > 0) {
      break;
    }
    else {
      cout << "Invalid input. number of students must be positive integer.\n";
      continue;
    }  
  }
  
  
  vector<student> stu;
  
  cout << "\nStudents info (by input order) : \n";
  for(int i = 0; i < n; i++) {
    cout << "\nstudent " << i+1 << endl;
    add_student(stu);
  }
  print(stu);
  cout << endl;

  // sorting by marks in descending order
  sort(stu.begin(), stu.end(), [](const student &a, const student &b) {
    if(a.marks != b.marks) {
      return a.marks > b.marks;
    }
    return a.roll < b.roll;  
  });

  cout << "\nStudents' merit wise info (by marks) : \n";
  print(stu);
  cout << endl;

  cout << "\nTop 3 students : \n";
  for(int i = 0; i < 3; i++) {
    cout << "\nTop " << i+1 << " : " << stu[i].roll 
         << "\t" << stu[i].name << "\t" << stu[i].marks << endl;
  }

  return 0;
}