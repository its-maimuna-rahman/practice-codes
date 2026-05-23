#include <stdio.h>
int main() {
  int grade, s = 0, n = 0;
  float avg;
  
  printf("enter grade (-1 to stop)\n");
  scanf("%d", &grade);
  
  while(grade != -1) {
    s = s + grade;
    n++;
    scanf("%d", &grade);
  }
  
  if(n != 0) {
    avg = (float)s/n;
    printf("avg = %f", avg);
  }
  else {
    printf("math error");
  }
  
  return 0;
}