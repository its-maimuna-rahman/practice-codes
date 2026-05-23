// learning string basics in cpp

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "Max";
  
  cout << "string originally taken : " << s << endl;
  cout << "string length = " << s.length() << endl;     // length (3)
  
  s.append(" Verstappen");                              // append (Max Verstappen)
  cout << "string append change : " << s << endl;
  
  s.insert(3, " GOAT");                                 // insert (Max GOAT Verstappen)
  cout << "string insert change : " << s << endl;
  
  s.erase(3, 5);                                        // erase (Max Verstappen)
  cout << "string erase change : " << s << endl;
  
  s.replace(4, 11, "is 4 time world champion");         // replace (Max is 4 time world champion)
  cout << "string replace change : " << s << endl;
  
  cout << "sub string : " << s.substr(7, 21) << endl;   // sub string (4 time world champion)
  cout << "find (champion) : " << s.find("champion") << endl;   // find (20)
  
  cout << endl;
  string numStr = "123";
  int x = stoi(numStr);                         // string to int
  double y = stod("3.14");                      // string to double
  cout << "int + 10 = " << x + 10 << endl;     
  cout << "double + 1.0 = " << y + 1.0 << endl; 
  
  cout << endl;
  int n = 2025;
  string str = to_string(n);                      // int to string
  cout << str + " year" << endl; 
  
  return 0;
}
