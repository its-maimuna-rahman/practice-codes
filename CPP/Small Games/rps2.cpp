#include <iostream>
#include <random>
#include <limits>
#include <cctype>

char valid_input(int player_num) {
  char choice;
    
    std::cout << "player " << player_num << " choice : ";
    std::cin >> choice;
    
    while(choice != 'r' && choice != 'p' && choice != 's') {
      std::cout << "Invalid input. choose r/p/s.\n";
      std::cout << "player " << player_num << " choice : ";
      std::cin >> choice;
    }
    
    return choice;
  }
  
  char com_input() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 2);
    
    int randomNum = dis(gen);
    if (randomNum == 0) return 'r';
    if (randomNum == 1) return 'p';
    return 's';
  }
  
  int result(char p1, char p2) {
    if(p1 == p2) {
      return 0;
    }
    else if(p1 == 'r' && p2 == 's' ||
            p1 == 'p' && p2 == 'r' ||
            p1 == 's' && p2 == 'p') {
      return 1;
    }
    else {
      return 2;
    }
  }
  
  std::string choice_name(char c) {
    if (c == 'r') return "Rock";
    if (c == 'p') return "Paper";
    if (c == 's') return "Scissor";
    return "Unknown";
  }
  
  int main() {
    int mode, rounds, p1_choice, p2_choice, p1_point = 0, p2_point = 0;
    std::cout << "\n============== ROCK, PAPER, SCISSOR ==============\n";
    std::cout << "1. 2 players\n";
    std::cout << "2. player vs computer\n";
    std::cout << "Enter mode (1 or 2) : ";
    std::cin >> mode;
    
    while(mode != 1 && mode != 2) {
      std::cout << "invalid input for mode.\n";
      std::cout << "Enter mode (1 or 2) : ";
      std::cin >> mode;
    }
    
    std::cout << "how many rounds you want to play ? = ";
    std::cin >> rounds;
    
    while(rounds <= 0) {
      std::cout << "invalid input for round. enter a positive integer\n";
      std::cout << "how many rounds you want to play ? = ";
      std::cin >> rounds;
    }
    
    std::cout << "\nGame Started! (r = Rock, p = Paper, s = Scissor)\n" << std::endl;
    
    for(int i = 0; i < rounds; i++) {
      if(mode == 1) {
    
          p1_choice = valid_input(1);
          p2_choice = valid_input(2);
          std::cout << "Player 1 chose : " << choice_name(p1_choice) << std::endl;
          std::cout << "Player 2 chose : " << choice_name(p2_choice) << std::endl;
          
          if(result(p1_choice, p2_choice) == 0) {
            std::cout << "Draw\n";
          }  
          else if (result(p1_choice, p2_choice) == 1) {
            std::cout << "Player 1 won this round\n";
              p1_point++;
          }
          else if (result(p1_choice, p2_choice) == 2) {
                std::cout << "Player 2 won this round\n";
                p2_point++;
         }
         std::cout << "\n";  
      }  
      else  {
          p1_choice = valid_input(1);
          p2_choice = com_input();
          std::cout << "Player 1 chose : " << choice_name(p1_choice) << std::endl;
          std::cout << "Computer chose : " << choice_name(p2_choice) << std::endl;
          
          if(result(p1_choice, p2_choice) == 0) {
            std::cout << "Draw\n";
          }  
          else if (result(p1_choice, p2_choice) == 1) {
            std::cout << "Player 1 won this round\n";
            p1_point++;
          }
          else if (result(p1_choice, p2_choice) == 2) {
              std::cout << (mode == 1 ? "Player 2" : "Computer") << " won this round\n";
              p2_point++;
          }
          std::cout << "\n";  
      }
    }
    
    std::cout << "======== Result ========\n";
    if(p1_point == p2_point) {
      std::cout << "\nIt's a draw\n";
    }
    else if(p1_point > p2_point) {
      std::cout << "\nPlayer 1 wins\n";
    }
    else {
      std::cout << "\n" << (mode == 1 ? "Player 2" : "Computer") <<  " wins.\n";
    }
    
    std::cout << "\n======== score board ========\n";
    std::cout << "Player 1 : " << p1_point << std::endl; 
    std::cout << (mode == 1 ? "Player 2" : "Computer") << " : " << p2_point <<std::endl;
  
    
    return 0;
  }