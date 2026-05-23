// password enter with only 3 tries

#include <stdio.h>
#include <string.h>

int main() {
  char correct_pin[] = "1234";
  char input[10];
  
  for (int i = 1; i <= 3; i++) {
    printf("Enter PIN: ");
    scanf("%s", input);   // read string
    
    if (strcmp(input, correct_pin) == 0) {
      printf("Access Granted!\n");
      return 0;
    } else {
      printf("Wrong PIN!\n");
    }
  }
  
  printf("Card Blocked! Too many wrong attempts.\n");
  return 0;
}
