// loop until password match, password is : abc123
#include <stdio.h>
#include <string.h>

int main() {
  char x[6];
  
  while (1) {   // infinite loop
    printf("Enter password = ");
    scanf("%s", &x);
    
    if (strcmp(x, "abc123") == 0) {
      break;   // state satisfied → exit loop
    }
    
    printf("Incorrect password. try again\n");
  }
  printf("YAyyyyyyyy, correct password\n");
  return 0;
}
