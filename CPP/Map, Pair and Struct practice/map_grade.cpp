// Student Performance Tracker
// Each input: student_name subject marks
// A student can appear multiple times
// Store data so that each student has all their marks
// Compute average marks of each student
// Display students whose average >= 60
// Output sorted by student name

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

struct student {
  std::string name;
  std::string subject;
  int mark;
};

int main() {
  int n;
  std::vector<student> students;
  student s;
  
  std::cout << "\nEnter number of inputs : ";
  std::cin >> n;
  std::cout << std::endl;
  
  for(int i = 0; i < n; i++) {
    std::cout << "Enter student name : ";
    std::cin >> s.name;
    std::cout << "Enter subject name : ";
    std::cin >> s.subject;
    std::cout << "Enter mark : ";
    std::cin >> s.mark;
    
    students.push_back(s);
    std::cout << std::endl;
  }
  
  std::map<std::string, std::vector<student>> name_map;
  
  for(auto it : students) {
    name_map[it.name].push_back(it);
  }
  
  std::cout << "Student wise marks : \n";
  std::cout << std::endl;
  for(auto it : name_map) {
    std::cout << "Name : " << it.first << std::endl;
    
    for(auto x : it.second) {
      std::cout << "\tsubject : " << x.subject
                << "\t\tMarks : " << x.mark << std::endl;
    }
    std::cout << std::endl;
  }
  
  // average calculation
  std::cout << "\nAverage mark above 60\n\n";
  for(auto it : name_map) {
    int counter = 0, sum = 0;
    for(auto x : it.second) {
      sum+= x.mark;
      counter++;
    }
    if((sum/counter) > 60) {
      std::cout << "Name : " << it.first
                << "\tAverage : " << sum/counter << std::endl;
    }                
  }
  
  return 0;
}