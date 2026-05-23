/*Develop a C program that will determine if a department store
 customer has exceeded the credit limit on a charge account. For each customer
 the following facts are available:
 a) Account number
 b) Balance at the beginning of the month
 c) Total of all items charged by this customer this month
 d) Total of all credits applied to this customer's account this month
 e) Allowed credit limit
 The program should input each fact, calculate the new balance
 (= beginning balance + charges–credits), and determine whether the new balance
 exceeds the customer's credit limit. For those customers whose credit limit is
 exceeded, the program should display the customer's account number, credit
 limit, new balance and the message “Credit limit exceeded.”*/

#include <stdio.h>

int main(void) {
  int acc_num;
  float begin_bal, charge, credit, credit_lim, new_bal;
  
  printf("Enter account number (-1 to end) : ");
  scanf("%d", &acc_num);
  
  while(acc_num != -1) {
    
    printf("Enter  beginning balance : ");
    scanf("%f", &begin_bal);
    printf("Enter total charges : ");
    scanf("%f", &charge);
    printf("Enter total credits : ");
    scanf("%f", &credit);
    printf("Enter credit limit : ");
    scanf("%f", &credit_lim);
    
    new_bal = begin_bal + charge - credit;
    
    if(new_bal > credit_lim) {
      printf("\nAccount : %d\n",acc_num);
      printf("Credit Limit : %.2f\n", credit_lim);
      printf("Balance : %.2f\n", new_bal);
      printf("\nCredit Limit Exceeded.\n");
    }
    else {
      printf("\nAccount : %d\n",acc_num);
      printf("Credit Limit : %.2f\n", credit_lim);
      printf("Balance : %.2f\n", new_bal);
      printf("Credit Limit haven't exceeded\n");
    }
    
    printf("\nEnter account number (-1 to end) : ");
    scanf("%d", &acc_num);
  }
  
  return 0;
}