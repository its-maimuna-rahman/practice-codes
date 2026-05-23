/*Write a C++ program using nested if statements to determine not only the triangle
 *  type by sides,
 but also by angles (using Pythagoras theorem)*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double a,b,c;
  
  cout << endl << "enter a,b,c = " << endl;
  cin >> a >> b >> c;
  
  if(a + b > c && b + c > a && a + c > b) {
    cout << "a,b,c forms a triangle" << endl;
    
    if(a == b && b == c && c == a) {
      cout << "equilateral triangle" << endl;
      
      if(pow(a,2) + pow(b,2) == pow(c,2)) {
        cout << "right angled triangle" << endl;
      }
      else if(pow(a,2) + pow(b,2) >= pow(c,2)) {
        cout << "acute angled triangle" << endl;
      }
      else {
        cout << "obtuse angled triangle" << endl;
      }
      
    }
    else if(a == b && b != c || a != b && b == c || a != c && c == b) {
      cout << "isosceles triangle" << endl;
      
      if(pow(a,2) + pow(b,2) == pow(c,2)) {
        cout << "right angled triangle" << endl;
      }
      else if(pow(a,2) + pow(b,2) >= pow(c,2)) {
        cout << "acute angled triangle" << endl;
      }
      else {
        cout << "obtuse angled triangle" << endl;
      }
      
    }
    else if(a != b && b != c && c != a) { // can not put condi. in ELSE 
      cout << "scalene triangle" << endl;
      
      if(pow(a,2) + pow(b,2) == pow(c,2)) {
        cout << "right angled triangle" << endl;
      }
      else if(pow(a,2) + pow(b,2) >= pow(c,2)) {
        cout << "acute angled triangle" << endl;
      }
      else {
        cout << "obtuse angled triangle" << endl;
      }
      
    }
    
  }
  else {
    cout << "invalid. a,b,c do not form a triangle" << endl;
  } 
  
  
  return 0;
}