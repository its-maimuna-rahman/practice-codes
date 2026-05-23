/*airlines seat reservation program.
 *capacity = 10 seats, (1-10) first class (type 1), (10-20) economy class (type
 2).
 *program should print boarding pass (seat num and seat type).
 
 *Initialize all the elements of the array to 0 to indicate that all seats are
 empty. As each seat is assigned, set the corresponding element of the array
 to 1 to indicate that the seat is no longer available.
 
 *When the first class section is full, your program should ask the person if
 it’s acceptable to be placed in the economy section (and vice versa). If yes,
 then make the appropriate seat assignment. If no, then print the message
 "Next flight leaves in 3 hours */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==== to check whether the flight is full or not ====
int full(int first[5][2], int econ[5][2]) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 2; j++) {
      if(first[i][j] == 0 || econ[i][j] == 0) {
        return 0; // still empty
      }
    }
  }
  return 1; // full
}

// ==== to check first class seats are full or not ====
int f_full(int first[5][2]) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 2; j++) {
      if(first[i][j] == 0) {
        return 0; // still empty
      }
    }
  }
  return 1; // full
}

// ==== to check economy class seats are full or not ====  
int e_full(int econ[5][2]) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 2; j++) {
      if(econ[i][j] == 0) {
        return 0; // still empty
      }
    }
  }
  return 1; // full
}

// ==== to take input for a first class seat ====
int first_seat(int first[5][2]) {
  int row, col;
  row = rand() % 5;
  col = rand() % 2;
  
  while(first[row][col] == 1) {
    row = rand() % 5;
    col = rand() % 2; 
  }
  
  first[row][col] = 1;
  printf("\nAssigned FIRST CLASS seat --> Row %d, Column %d\n", row + 1, col + 1);
  
  // ==== creating boarding pass ====
  printf("\n========================================================\n");
  printf("                   ~~~ BOARDING PASS ~~~                 \n");
  printf("||  Seat type : FIRST CLASS\n");
  printf("||  Assigned FIRST CLASS seat --> Row %d, Column %d\n", row + 1, col + 1);
  printf("========================================================\n");
  
  return 0;
}

// ==== to take input for an economy class seat ====
int econ_seat(int econ[5][2]) {
  int row, col;
  row = rand() % 5;
  col = rand() % 2;
  
  while(econ[row][col] == 1) {
    row = rand() % 5;
    col = rand() % 2; 
  }
  
  econ[row][col] = 1;
  printf("\nAssigned ECONOMY CLASS seat --> Row %d, Column %d\n", row + 1, col + 1);
  
  // ==== creating boarding pass ====
  printf("\n========================================================\n");
  printf("                   ~~~ BOARDING PASS ~~~                 \n");
  printf("||  Seat type : ECONOMY CLASS\n");
  printf("||  Assigned ECONOMY CLASS seat --> Row %d, Column %d\n", row + 1, col + 1);
  printf("========================================================\n");
  
  return 0;
}

// ==== to show output ====
int show_output(int first[5][2], int econ[5][2]) {
  
  // updated first class seats
  printf("\nUpdated First Class Seats:\n");
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 2; j++) {
      printf("%d ", first[i][j]);
    }
    printf("\n");
  }
  
  // updated economy class seats
  printf("\nUpdated Economy Class Seats:\n");
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 2; j++) {
      printf("%d ", econ[i][j]);
    } 
    printf("\n");
  }
  
  return 0;
}



int main() {
  int s = 0, type;
  int first[5][2] = {0}, econ[5][2] = {0};
  int efull, ffull;
  srand(time(NULL));
  
  printf("\n===== FLIGHT RESERVATION SYSTEM =====\n");
  
  //first class initial seat condition, 0 = empty, 1 = full
  printf("\nFirst class : \n");
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 2; j++) {
      printf("%d ", s);
    }
    printf("\n");
  } 
  printf("\n");
  
  //economy class initial seat condition, 0 = empty, 1 = full
  printf("\nEconomy class : \n");
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 2; j++) {
      printf("%d ", s);
    } 
    printf("\n");
  }
  
  while(1) {
    
    // seat type input
    printf("\nfirst class (type 1) or economy class (type 2) ? = ");
    scanf("%d", &type);
    
    // checking whether the input is valid or not
    while(1) {
      
      if(type == 1 || type == 2) {
        break;
      }
      else {
        printf("Invalid input for type\n");
        printf("first class (type 1) or economy class (type 2) ? = ");
        scanf("%d", &type);
      }
    }
    
    // type 1 and 2 seat allocation to the passengers
    if(type == 1) {
      if(!f_full(first)) {
            first_seat(first);
      }
      // if first class is full
      else if(f_full(first)) {
            printf("First class seats are full. Wanna consider Economy class seat ? (1. yes, 2. no) : ");
            scanf("%d", &ffull);
          
          // checking whether the input is valid or not
          while(ffull != 1 && ffull != 2) {
            printf("Invalid input.\n");
            printf("First class seats are full. Wanna consider Economy class seat ? (1. yes, 2. no) : ");
            scanf("%d", &ffull);
          }
          
          if (ffull == 1) {
            econ_seat(econ);       // assign seat in economy class
          }
          else if (ffull == 2) {
            printf("Please wait for the next flight.\n");
          }
      }
    }
    else if(type == 2) {
      if(!e_full(econ)) {
            econ_seat(econ);
      }
      // if economic class is full
      else if(e_full(econ)) {
            printf("Economy class seats are full. Wanna consider First class seat ? (1. yes, 2. no) : ");
            scanf("%d", &efull);
          
          // checking whether the input is valid or not
          while(efull != 1 && efull != 2) {
            printf("Invalid input.\n");
            printf("Economy class seats are full. Wanna consider First class seat ? (1. yes, 2. no) : ");
            scanf("%d", &efull);
          }
          
          if(efull == 1) {
            first_seat(first);    // assign seat to first class
          } 
          else if(efull == 2){
            printf("Please wait for next flight.\n");
          }
      }
    }
    
    //updated flight condition  
    show_output(first, econ);
    
    // close the program if the flight is full
    if(full(first, econ)) {
      printf("the flight is full.\n");
      return 0;
    }
    
  }
  
  return 0;
}
