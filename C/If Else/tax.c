/*Write a C program using nested if statements to calculate income tax based on income and gender:
  
  Gender	  Income Range	   Tax Rate
  Male	 ≤  300000	          0%
  Male	    300001–700000	    10%
  Male	 >  700000	          20%
  Female ≤  350000	          0%
  Female	  350001–700000	    8%
  Female >  700000	          18%
*/
 
#include <stdio.h>
#include <math.h>  
int main() {
  char g;
  int x, tax;
  
  printf("enter gender (M OR F) = ");
  scanf(" %c", &g);
  
  printf("enter income = ");
  scanf("%d", &x);
  
  if(g=='M') {
    if(x<=300000) {
      tax=x*0;
      printf("tax = %d", tax);
    }
    else if(x>=300001 && x<=700000) {
      tax=x*0.1;
      printf("tax = %d", tax);
    }
    else if(x>700000) {
      tax=x*0.2;
      printf("tax = %d", tax);
    }
  }
  else if(g=='F') {
    if(x<=350000) {
      tax=x*0;
      printf("tax = %d", tax);
    }
    else if(x>=350001 && x<=700000) {
      tax = x*0.08;
      printf("tax = %d", tax);
    }
    else if(x>700000) {
      tax=x*0.18;
      printf("tax = %d", tax);
    }
  }
  else {
    printf("invalid input for gender");
  }
  
  return 0;
}