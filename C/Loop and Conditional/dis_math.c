#include <stdio.h>

int main() {
  int A, B, C;
 
 printf("\n========== DISCRETE MATHEMATICS ==========\n");
 printf("\n----- Truth Table for AND operation -----\n");
 printf("-------------------------------------------------------\n");
 printf("\tA\tB\tC\t|\tA & B & C\n");
 printf("-------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d\n", A, B, C, A & B & C);
      }
    }
  }
  
  printf("\n----- Truth Table for OR operation -----\n");
  printf("-------------------------------------------------------\n");
  printf("\tA\tB\tC\t|\tA V B V C\n");
  printf("-------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d\n", A, B, C, A || B || C);
      }
    }
  }
  
  printf("\nTruth Table for NOT operation\n");
  printf("------------------------------------------------------------\n");
  printf("\tA\tB\tC\t|\t!A | \t!B | \t!C\n");
  printf("------------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d  | \t%d  | \t%d\n", A, B, C, !A, !B, !C);
      }
    }
  }
  
  printf("\n----- Truth Table for XOR operation -----\n");
  printf("-------------------------------------------------------\n");
  printf("\tA\tB\tC\t|\tA ^ B ^ C\n");
  printf("-------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d\n", A, B, C, A ^ B ^ C);
      }
    }
  }
  
  printf("\n----- Truth Table for XNOR operation -----\n");
  printf("-------------------------------------------------------\n");
  printf("\tA\tB\tC\t|\t!(A ^ B ^ C)\n");
  printf("-------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d\n", A, B, C, !(A ^ B ^ C));
      }
    }
  }
  
  printf("\n----- Truth Table for De Morgan's law (1) -----\n");
  printf("-----------------------------------------------------------------\n");
  printf("\tA\tB\tC\t| !(A ^ B ^ C)\t| (!A v !B v !C)\n");
  printf("-----------------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d\t|\t%d\n", A, B, C, !(A && B && C), ((!A) || (!B) || (!C)));
      }
    }
  }
  
  printf("\n----- Truth Table for De Morgan's law (2) -----\n");
  printf("-----------------------------------------------------------------\n");
  printf("\tA\tB\tC\t| !(A v B v C)\t| (!A ^ !B ^ !C)\n");
  printf("-----------------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d\t|\t%d\n", A, B, C, !(A || B || C), ((!A) && (!B) && (!C)));
      }
    }
  }
  
  printf("\n----- Truth Table for NAND operation -----\n");
  printf("-------------------------------------------------------\n");
  printf("\tA\tB\tC\t|\t!(A & B & C)\n");
  printf("-------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d\n", A, B, C, !(A & B & C));
      }
    }
  }
  
  printf("\n----- Truth Table for NOR operation -----\n");
  printf("-------------------------------------------------------\n");
  printf("\tA\tB\tC\t|\t!(A V B V C)\n");
  printf("-------------------------------------------------------\n");
  for(A = 0; A <= 1; A++) {
    for(B = 0; B <= 1; B++) {
      for(C = 0; C <= 1; C++) {
        printf("\t%d\t%d\t%d\t|\t%d\n", A, B, C, !(A || B || C));
      }
    }
  }
  
  return 0;
}