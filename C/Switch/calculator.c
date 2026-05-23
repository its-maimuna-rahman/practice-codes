/*input 2 int
 * input math operation (+,-,*,/,%)
 * switch for choosing operation
 * if statement under division by 0
 * print output
 * */

#include <stdio.h>
int main() {
  int x, y;
  float res;
  char op;
  
  printf("enter x,y = ");
  scanf("%d%d", &x, &y);
  printf("enter math operation (+,-,*,/,%) = ");
  scanf(" %c", &op);
  
  switch(op) {
  case '+' : res=x+y;
             printf("result = %.2f\n", res);
             break;
  case '-' : res=x-y;
             printf("result = %.2f\n", res);
             break;
  case '*' : res=x*y;
             printf("result = %.2f\n", res);
             break;
  case '/' : if(y!=0) {
                res=(float)x /  y;
                printf("result = %.2f\n", res);
             }
             else if(y==0) {
                printf("math error\n");
             }
              break;
  case '%' : if(y!=0) {
                int mod_res= x%y;
                printf("result = %d\n", mod_res);
             }
             else if(y==0) {
                printf("math error\n");
             }
              break;
  default :
              printf("invalid input for math operation\n");
              break;
  
  }
  
  return 0;
}