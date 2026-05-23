// simple rock, paper, scissor program for 2 player

#include <iostream>

int main() {
  char p1, p2;
  int n;
  
  std::cout << std::endl << "rock = r" << std::endl << "paper = p" << std::endl <<"scissor = s" << std::endl;
  std::cout << "How many points you wanna play ? n = ";
  std::cin >> n;
  std::cout << std::endl;
  
  int count1 = 0, count2 = 0;
  
  for(int i = 0; i < n; i++) {
    std::cout << "Enter player 1's choice = ";
    std::cin >> p1;
    std::cout << "Enter player 2's choice = ";
    std::cin >> p2;
    
    switch(p1) {
    
        case 'r' :
                    
                    switch(p2) {
                    case 'r' : 
                               std::cout << "draw" << std::endl;
                               break;
                    case 'p' : 
                               std::cout << "player 2 wins" << std::endl;
                               count2++;
                               break;      
                    case 's' : 
                               std::cout << "player 1 wins" << std::endl;
                               count1++;
                               break;
                    default : 
                               std::cout << "invalid input for player 2" << std::endl;
                               break;
                    }
          
                    break;
          
        case 'p' : 
          
                    switch(p2) {
                    case 'r' : 
                               std::cout << "player 1 wins" << std::endl;
                               count1++;
                               break;
                    case 'p' : 
                               std::cout << "draw" << std::endl;
                               break;
                    case 's' : 
                               std::cout << "player 2 wins" << std::endl;
                               count2++;
                               break;
                    default  : 
                               std::cout << "invalid input for player 2" << std::endl;
                               break;
                    }
          
                    break;
          
        case 's' : 
          
                    switch(p2) {
                    case 'r' : 
                               std::cout << "player 2 wins" << std::endl;
                               count2++;
                               break;
                    case 'p' : 
                               std::cout << "player 1 wins" << std::endl;
                               count1++;
                               break;
                    case 's' : 
                               std::cout << "draw" << std::endl;
                               break;
                    default  : 
                               std::cout << "invalid input for player 2" << std::endl;
                               break;
                    }
          
                    break;
          
        default :
                  
                  std::cout << "invalid input for player 1" << std::endl;
                  break;
          
    }
    std::cout << std::endl;
  }
  
  
  std::cout << std::endl << "RESULTS" << std::endl;
  if(count1 > count2) {
    std::cout << std::endl << "player 1 wins" << std::endl;
  }
  else if(count2 > count1) {
    std::cout << std::endl << "player 1 wins" << std::endl;
  }
  else if(count2 == count1) {
    std::cout << std::endl << "draw" << std::endl;
  }
  
  std::cout << std::endl;
  std::cout << "score : player 1 = " << count1 << "  points" << std::endl; 
  std::cout << "score : player 2 = " << count2 << "  points" << std::endl;
  
  return 0;
}