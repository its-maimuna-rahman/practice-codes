#include <stdio.h>
#include <string.h>

int main() {
  int n;
  
  printf("Enter number of elements = ");
  scanf("%d", &n);
  
  char string[n][20];   // element = 20, max per ele size = 20 char
  char search[20];
  
  
  printf("Enter elements = \n");
  for(int i = 0; i < n; i++) {
    scanf(" %s", &string[i]);
  }
  
  printf("The array of strings = \n");
  for(int i = 0; i < n; i++) {
    printf("%s ", string[i]);
  }
  
  printf("\n");
  printf("Enter a element to search = ");
  scanf(" %s", &search);
  
  int found = 0;
  
  for(int i = 0; i < n; i++) {
    if(strcmp(string[i], search) == 0) {
      printf("Found at index = %d", i);
      found = 1;
    }
  }
  
  if(!found) {
    printf("not found\n");
  }
  
  return 0;
}