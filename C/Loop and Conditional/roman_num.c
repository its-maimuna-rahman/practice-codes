// decimal to roman numbering (1-100)

#include <stdio.h>

void roman(int num) {
  // Arrays of Roman symbols and their values
  int values[] =    {100, 90, 50, 40, 10, 9, 5, 4, 1};
  char *symbols[] = {"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  
  for (int i = 0; i < 9; i++) {
    while (num >= values[i]) {
      printf("%s", symbols[i]);
      num -= values[i];
    }
  }
}

int main() {
  printf("Decimal\t | Roman\n");
  printf("---------------------\n");
  
  for (int i = 1; i <= 100; i++) {
    printf("%3d\t | ", i);
    roman(i);
    printf("\n");
  }
  
  return 0;
}
