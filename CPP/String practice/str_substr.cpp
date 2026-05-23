// Extract username from an email.
// Print first and last 3 characters.
// Remove first and last character.
// Validate email:  must contain @ and no spaces

#include <iostream>
#include <string>

int main() {
  std::string email, username;
  bool valid = false;
  
  while(!valid) {
    username.clear();   // IMPORTANT
    std::cout << "Enter email : ";
    getline(std::cin, email);
    
    int len = email.length();
    bool has_at = false;
    bool has_space = false;
    
    for(int i = 0; i < len; i++) {
      if(email[i] == ' ') {
        has_space = true;
      }
      if(email[i] == '@') {
        has_at = true;
      }
    }
    
    if(has_space == true) {
      std::cout << "Error: Email cannot contain spaces. Try again!\n" << std::endl;
      continue;
    }
    
    if(has_at == false) {
      std::cout << "Error: Email must contain '@' symbol.  Try again!\n" << std::endl;
      continue;
    }
    
    for(int i = 0; i < len; i++) {
      if(email[i] == '@') {
        username = email.substr(0, i);
        break;
      }
    } 
    
    valid = true;
  } 
  
  std::cout << "\nUsername : \n" << username << std::endl;
  std::cout << "\nFirst character : " << username[0] << std::endl;
  std::cout << "Last character : " << username[username.length()-1] << std::endl;
  std::cout << "Removing first and last character : "
            << username.substr(1, username.length()-2); 
  
  return 0;
} 