// weekly pay calculator for a company
// managers - fixed weekly salary ($1500)
// hourly workers - fixed hourly wage ($12) for up to 40h, 1.5 times the wage for
// overtime
// commission workers - $250 + 5.7% of their gross weekly sales
// piece workers - receive fixed amount of money for each items they produce
// (each worker produce only 1 type of item)

#include <stdio.h>

int main() {
  int choice, code, item;
  float hw_hour, hw_pay, cw_sale, cw_pay, pw_pay;
  
  while(1) {
    printf("\n======= WEEKLY PAY CALCULATOR =======\n");
    printf("1. Manager\n");
    printf("2. Hourly worker\n");
    printf("3. Commission worker\n");
    printf("4. Piece worker\n");
    printf("5. EXIT\n");
    printf("\nChoose category (1/2/3/4/5) : ");
    scanf("%d", &choice);
    printf("\n");
    
    switch(choice) {
    
    case 1 :
      
      printf("------- Manager -------\n"); 
      printf("\nSalary of the manager : $1500\n");
      continue;
      
    case 2 :
      
      printf("------- Hourly worker -------\n");
      printf("Enter the amount of hours the worker has worked : ");
      scanf("%f", &hw_hour);
      
      while(1) {
        if(hw_hour >= 0) {
          break;
        }
        else {
          printf("Invalid input for hours. (hours >= 0)\n");
          printf("Enter the amount of hours the worker has worked : ");
          scanf("%f", &hw_hour);
        }
      }
      
      if(hw_hour <= 40) {
          hw_pay = hw_hour * 12;
      }
      else {
        hw_pay = (40 * 12) + ((hw_hour - 40) * (12 * 1.5));
      }
      
      printf("\nSalary of the hourly worker = $%.2f\n", hw_pay);
      continue;
      
    case 3 :
      
      printf("------- Commission worker -------\n");
      printf("Enter gross weekly sales ($) of the worker : ");
      scanf("%f", &cw_sale);
      
      while(1) {
        if(cw_sale >= 0) {
          break;
        }
        else {
          printf("Invalid input for sales. (sales >= 0)\n");
          printf("Enter gross weekly sales ($) of the worker : ");
          scanf("%f", &cw_sale);
        }
      }
      
      cw_pay = 250 + (0.057 * cw_sale);
      
      printf("\nSalary of the comission worker = $%.2f\n", cw_pay);
      continue;
      
    case 4 :
      
      printf("------- Piece worker -------\n");
      printf("wage list (for producing per unit of the product)\n");
      printf("Item 1 : $30.75\n");
      printf("Item 2 : $35.50\n");
      printf("Item 3 : $40.25\n");
      printf("Item 4 : $45.00\n");
      
      printf("Enter item code : ");
      scanf("%d", &code);
      
      while(1) {
        if(code >= 1 && code <= 4) {
          break;
        }
        else {
          printf("Invalid input for code. (code = 1/2/3/4)\n");
          printf("Enter item code : ");
          scanf("%d", &code);
        }
      }
      
      printf("Enter the number of items the worker has produced : ");
      scanf("%d", &item);
      
      while(1) {
        if(item >= 0) {
          break;
        }
        else {
          printf("Invalid input for number of items. (item >= 0)\n");
          printf("Enter the number of items the worker has produced : ");
          scanf("%d", &item);
        }
      }
      
      if(code == 1) {
        pw_pay = item * 30.75;
      }
      else if(code == 2) {
        pw_pay = item * 35.50;
      }
      else if(code == 3) {
        pw_pay = item * 40.25;
      }
      else if(code == 4) {
        pw_pay = item * 45.00;
      }
      
      printf("\nSalary of the piece worker = $%.2f\n", pw_pay);
      continue;
      
    case 5 :
      
      printf("\nEXIT\n");
      return 0;
      
    default : 
      
      printf("INVALID CHOICE. choose 1/2/3/4/5\n");
      continue;
    
    }
  }
  
    return 0;
  }