/*Write a C program using nested if statements to determine not only the triangle
 *  type by sides,
but also by angles (using Pythagoras theorem)*/

#include <stdio.h>
#include <math.h>  
int main(){
  int a,b,c;
  
  printf("enter a,b,c = ");
  scanf("%d%d%d", &a, &b, &c);
  
  if(a+b>c && b+c>a && a+c>b) {
    printf("a,b,c forms a triangle\n");
    
    if(a==b && b==c && c==a) {
      printf("equilateral triangle\n");
      
      if(pow(a,2)+pow(b,2)==pow(c,2)) {
        printf("right angled triangle\n");
      }
      else if(pow(a,2)+pow(b,2)>=pow(c,2)) {
        printf("acute angled triangle\n");
      }
      else {
        printf("obtuse angled triangle\n");
      }
      
    }
    else if(a==b && b!=c || a!=b && b==c || a!=c && c==b) {
      printf("isosceles triangle\n");
      
      if(pow(a,2)+pow(b,2)==pow(c,2)) {
        printf("right angled triangle\n");
      }
      else if(pow(a,2)+pow(b,2)>=pow(c,2)) {
        printf("acute angled triangle\n");
      }
      else {
        printf("obtuse angled triangle\n");
      }
      
    }
    else if(a!=b && b!=c && c!=a) { // can not put condi. in ELSE 
      printf("scalene triangle\n");
      
      if(pow(a,2)+pow(b,2)==pow(c,2)) {
        printf("right angled triangle\n");
      }
      else if(pow(a,2)+pow(b,2)>=pow(c,2)) {
        printf("acute angled triangle\n");
      }
      else {
        printf("obtuse angled triangle\n");
      }
      
    }
    
  }
  else {
    printf("invalid. a,b,c do not form a triangle\n");
  }
  
  
  return 0;
}