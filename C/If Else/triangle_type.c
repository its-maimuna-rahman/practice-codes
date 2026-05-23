//Write a C program using nested if statements to check whether a triangle is
//equilateral, isosceles, scalene, or invalid (if sides don’t form a triangle).

#include <stdio.h>
#include<math.h>
int main(){
  int a,b,c;
  
  printf("enter a,b,c = ");
  scanf("%d%d%d", &a, &b, &c);
  
  if(a+b>c && b+c>a && a+c>b) {
    printf("a,b,c forms a triangle\n");
    
    if(a==b && b==c && c==a) {
      printf("equilateral triangle\n");
    }
    else if(a==b && b!=c || a!=b && b==c || a!=c && c==b) {
      printf("isosceles triangle\n");
    }
    else if(a!=b && b!=c && c!=a) { // can not put condi. in ELSE 
      printf("scalene triangle\n");
    }
    
  }
  else {
    printf("invalid. a,b,c do not form a triangle\n");
  }
  return 0;  
  
}