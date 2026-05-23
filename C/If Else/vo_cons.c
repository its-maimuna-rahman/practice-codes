//Write a C program to check whether a character entered by the user is an uppercase letter,
//lowercase letter, digit, or special symbol using nested if statements.


#include <stdio.h>
int main(){
  char x;
  printf("enter char = ");
  scanf(" %c", &x);
  
  if(x>='a'&& x<='z') {
    printf("lowercase\n");
    if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') {
      printf("vowel\n");
    }
    else {
      printf("consonant\n");
    }
  }  
  else if(x>='A' && x<='Z') {
    printf("uppercase\n");
    if(x=='A'||x=='E'||x=='I'||x=='O'||x=='U') {
      printf("vowel\n");
    }
    else {
      printf("consonant\n");
    }  
  }
  else if(x>='0' && x<='9') {
    printf("number");
  }
  else {
    printf("symbol");
  }
    
  return 0;
}