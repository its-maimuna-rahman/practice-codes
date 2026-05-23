#include <iostream>
#include <limits>

void grid(char a[3][3], int row, int col, char player) {
  
  a[row][col] = player;
  
  std::cout << "\n-------------\n";
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      std::cout << "| " << a[i][j] << " ";
    }
    std::cout << "\n-------------\n";
  }
}

bool already_taken(char a[3][3], int row, int col) {
  if (a[row][col] != ' ') return true;
  else return false;
}

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

int main() {
  int r1, c1, r2, c2, counter = 0;
  
  char a[3][3] = {{' ', ' ', ' '},
  {' ', ' ', ' '},
  {' ', ' ', ' '}};
  
  std::cout << "\n========== TIC TAC TOE ==========\n" << std::endl;
  
  grid(a, 0, 0, ' ');
  std::cout << std::endl;
  
  while(1) {
    std::cout << "Enter player 1's move (O) : (row, column) : ";
    std::cin >> r1 >> c1;
    
    while(1) {
      
      if (r1 < 0 || r1 > 2 || c1 < 0 || c1 > 2) {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
      }
      else if(already_taken(a, r1, c1) == true) {
        std::cout << "The block is already taken.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else {
        break;
      }
      
      std::cout << "Enter player 1's move (O) : (row, column) : ";
      std::cin >> r1 >> c1;  
      
    }
    
    grid(a, r1, c1, 'O');
    
    if(result(a, 'O') == true) {
      std::cout << "Player 1 wins.\n";
      return 0;
    }
    else if(result(a, 'X') == true) {
      std::cout << "Player 2 wins.\n";
      return 0;
    }
    
    counter++;
    if(counter == 9) {
      std::cout << "The grid is full. It's a draw.\n";
      break;
    }
    
    std::cout << "Enter player 2's move (X) : (row, column) : ";
    std::cin >> r2 >> c2;
    
    while(1) {
      
      if(r2 < 0 || r2 > 2 || c2 < 0 || c2 > 2) {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
      }
      else if(already_taken(a, r2, c2) == true) {
        std::cout << "The block is already taken.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
      }
      else {
        break;
      }
      
      std::cout << "Enter player 2's move (X) : (row, column) : ";
      std::cin >> r2 >> c2;  
      
    }
    
    grid(a, r2, c2, 'X');
    
    if(result(a, 'O') == true) {
      std::cout << "\nPlayer 1 wins.\n";
      return 0;
    }
    else if(result(a, 'X') == true) {
      std::cout << "\nPlayer 2 wins.\n";
      return 0;
    }
    
    counter++;
    if(counter == 9) {
      std::cout << "\nThe grid is full. It's a draw.\n";
      break;
    }
  }
  
  
  return 0;
}