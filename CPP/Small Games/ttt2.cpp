#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

// Function to print the grid
void print_grid(char a[3][3]) {
  std::cout << "\n";
  for (int i = 0; i < 3; i++) {
    std::cout << " ";
    for (int j = 0; j < 3; j++) {
      std::cout << a[i][j];
      if (j < 2) std::cout << " | ";
    }
    std::cout << "\n";
    if (i < 2) std::cout << "---+---+---\n";
  }
  std::cout << "\n";
}

// Function to place the move
void place_move(char a[3][3], int row, int col, char player) {
  a[row][col] = player;
}

// Function to check if the block is already taken
bool already_taken(char a[3][3], int row, int col) {
  if (a[row][col] != ' ') return true;
  else return false;
}

// Function to get player input, place the move and print the updated grid
void player_input(char a[3][3], char player) {
  int move, r, c;
  while(true) {
    int counter = 1;
    
    std::cout << "Enter player " << player << "'s move : (1-9) : ";
    std::cin >> move;
    
    
    if (std::cin.fail()) {
      std::cout << "Invalid input. Please enter numbers\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if(move < 1 || move > 9) {
      std::cout << "Invalid. Enter between 1-9.\n";
      continue;
    }
    
    for(int i = 0; i < 3; i++) {          //r = (move - 1) / 3;
      for(int j = 0; j < 3; j++) {        //c = (move - 1) % 3;
        if(counter == move) {
          r = i;
          c = j;
        }
        counter++;
      }
    }
    
    if(already_taken(a, r, c) == true) {
      std::cout << "The block is already taken.\n";
      continue;
    }
    
    break;
  }    
  place_move(a, r, c, player);
  print_grid(a);
}

// Function to get computer input, place the move and print the updated grid
void computer_input(char a[3][3], char player) {
  int move, r, c;
  
  while(true) {
    move = rand() % 9 + 1;              // random number between 1 and 9
    
    r = (move - 1) / 3;                 // row and column conversion
    c = (move - 1) % 3;
    
    if(!already_taken(a, r, c)) {       // check if the position is empty
      break;                            // if empty, then the loop breaks 
    }
  }
  std::cout << "Computer chooses: " << move << std::endl;
  place_move(a, r, c, player);
  print_grid(a);
  
}

// Function to check if the player has won the round
bool result(char a[3][3], char p) {
  
  for(int i = 0; i < 3; i++) {
    if(a[i][0] == p && a[i][1] == p && a[i][2] == p)
      return true;
  }
  
  for(int j = 0; j < 3; j++) {
    if(a[0][j] == p && a[1][j] == p && a[2][j] == p)
      return true;
  }
  
  if(a[0][0] == p && a[1][1] == p && a[2][2] == p)
    return true;
  
  if(a[0][2] == p && a[1][1] == p && a[2][0] == p)
    return true;
  
  
  return false;
}

// Function to reset the grid
void grid_reset(char a[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a[i][j] = ' ';
    }
  }
}

int main() {
  int mode, rounds, random, counter = 0;
  int p1_score = 0, p2_score = 0;
  bool toss = true;
  bool turn = toss;
  char preference1, preference2;

  srand(time(NULL));
  // 1 and 2 toss, if 1, p1 starts, if 2, computer starts
  random = rand() % 2 + 1;
  
  char a[3][3] = {{' ', ' ', ' '},
                  {' ', ' ', ' '},
                  {' ', ' ', ' '}};
  
  std::cout << "\n========== TIC TAC TOE ==========\n" << std::endl;
  
  // Mode selection
  while(true) {
    
    std::cout << "\nMode 1 : Player vs Player\n";
    std::cout << "Mode 2 : Player vs Computer\n";
    std::cout << "\nChoose your mode : ";
    std::cin >> mode;
    
    if(mode != 1 && mode != 2) {
      std::cout << "\nInvalid input. Please choose 1 or 2.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    
    break;
  }
  
  if(mode == 1) std::cout << "\n========= Player vs Player =========\n";
  else if(mode == 2) std::cout << "\n========= Player vs Computer =========\n";
  
  // Round selection
  while(true) {
    std::cout << "\nHow many rounds you wanna play? : ";
    std::cin >> rounds;
    
    if(rounds <= 0) {
      std::cout << "Invalid input for round, enter postive number.\n";
      continue;
    }
    
    break;
  }
  std::cout << std::endl;
  
  // Player vs Player mode
  if(mode == 1) {
    
    // Preference selection
    while(true) {
      
      std::cout << "Enter player 1's preference (O/X).\n";
      std::cout << "Player 2 will automatically get the other one.\n\n";
      std::cout << "preference of player 1 : ";
      std::cin >> preference1;
      preference1 = toupper(preference1); 
      
      if(preference1 != 'O' && preference1 != 'X') {
        std::cout << "\nInvalid input. Please choose O or X.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      break;
    }
    
    // Preference assignment
    if(preference1 == 'O') preference2 = 'X';
    if(preference1 == 'X') preference2 = 'O';

    // Toss result
    std::cout << "Toss result : " << random << std::endl;
    std::cout << (random == 1 ? "Player will start" : "Computer will start");
    std::cout << std::endl;
    
    // for player 2 to start first
    if(random == 2) {       
      toss = false;
      turn = toss;
    }
    
    // Game loop
    for(int i = 0; i < rounds; i++) { 
      counter = 0;
      std::cout << "\n================== ROUND " << i+1 << " ==================\n";
      print_grid(a);
      
      while(true) {
        if(turn) {
          player_input(a, preference1);                     // Player 1 input                 
          
          if(result(a, preference1) == true) {              // Player 1 winning condition check
            std::cout << "Player 1 wins this round.\n";
            p1_score++;
            grid_reset(a);
            toss = !toss;
            turn = toss;
            break;
          }
        }
        else {
          player_input(a, preference2);                     // Player 2 input
          
          if(result(a, preference2) == true) {              // Player 2 winning condition check   
            std::cout << "\nPlayer 2 wins this round.\n";
            p2_score++;
            grid_reset(a);
            toss = !toss;
            turn = toss;
            break;
          }
        }
        
        counter++;
        if(counter == 9) {                                  // Draw condition check
          std::cout << "The grid is full. It's a draw in this round.\n";
          grid_reset(a);
          toss = !toss;
          turn = toss;
          break;
        }
        
        turn = !turn;
      }
    }
  }  
  
  // Player vs Computer mode
  if(mode == 2) {
    
    // Preference selection
    while(true) {
      
      std::cout << "Enter player 1's preference (O/X).\n";
      std::cout << "Computer will automatically get the other one.\n";
      std::cout << "preference of the player : ";
      std::cin >> preference1;
      preference1 = toupper(preference1);
      
      if(preference1 != 'O' && preference1 != 'X') {
        std::cout << "\nInvalid input. Please choose O or X.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      break;
    }
    
    // Preference assignment
    if(preference1 == 'O') preference2 = 'X';
    if(preference1 == 'X') preference2 = 'O';
    
    // Toss result
    std::cout << "Toss result : " << random << std::endl;
    std::cout << (random == 1 ? "Player will start" : "Computer will start");
    std::cout << std::endl;
    
    // for computer to start first
    if(random == 2) {       
      toss = false;
      turn = toss;
    }
    
    // Game loop
    for(int i = 0; i < rounds; i++) {
      counter = 0;
      std::cout << "\n================== ROUND " << i+1 <<" ==================\n";
      print_grid(a);
      
      while(true) {
        if(turn) {
          
          player_input(a, preference1);
          
          if(result(a, preference1) == true) {
            std::cout << "Player 1 wins this round.\n";
            p1_score++;
            grid_reset(a);
            toss = !toss;
            turn = toss;
            break;
          }
        }  
        else {
          
          computer_input(a, preference2);
          
          if(result(a, preference2) == true) {
            std::cout << "\nComputer wins this round.\n";
            p2_score++;
            grid_reset(a);
            toss = !toss;
            turn = toss;
            break;
          } 
        }
        
        counter++;
        if(counter == 9) {
          std::cout << "\nThe grid is full. It's a draw in this round.\n";
          grid_reset(a);
          toss = !toss;
          turn = toss;
          break;
        }
        
        turn = !turn;
      }
    }
  }
  
  // Score board
  std::cout << "\n================== SCORE BOARD ==================\n";
  std::cout << "\nTotal rounds played : " << rounds << std::endl;
  std::cout << "Player 1's score : " << p1_score << std::endl;
  std::cout << (mode == 1 ? "Player 2's score : " : "Computer's score : ")
            << p2_score << std::endl;
  
  if(p1_score > p2_score) std::cout << "Player 1 wins.\n";
  else if(p2_score > p1_score) std::cout << "Player 2 wins.\n";
  else if(p1_score == p2_score) std::cout << "It's a draw.\n";

  std::cout << std::endl;
  
  return 0;
}
