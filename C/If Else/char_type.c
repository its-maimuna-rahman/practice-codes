/* char type identifier
 * uppercase, lowercase, digit, special char
 * 
 */


#include <stdio.h>
int main() {
  char x;
  
  printf("enter x= ");
  scanf(" %c", &x);
  
  if(x >= 'a' && x <= 'z') {
    printf("lowercase\n");
    
    if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u') {
      printf("vowel\n");
    }
    else {
      printf("consonant\n");
    }
    
  }
  
  else if(x >= 'A' && x<= 'Z') {
    printf("uppercase\n"); 
        
    if (x=='A' || x=='E' || x=='I' || x=='O' || x=='U') {
      printf("vowel\n");
    }
    else {
      printf("consonant\n");
    }
      
  }
  else if(x >= '0' && x <= '9') {
    printf("digit\n");
  }
  else
    printf("special character\n");

  
  return 0;
}