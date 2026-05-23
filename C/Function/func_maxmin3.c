#include <stdio.h>
#include <math.h>

int max_3_int(int *x, int *y, int *z) {
  if(*x > *y && *x > *z) {
    return *x;
  }
  else if(*y > *x && *y > *x) {
    return *y;
  }
  else {
    return *z;
  }
}

int min_3_int(int *x, int *y, int *z) {
  if(*x < *y && *x < *z) {
    return *x;
  }
  else if(*y < *x && *y < *x) {
    return *y;
  }
  else {
    return *z;
  }
}

int main(void) {
  int x, y, z;
  
  printf("x, y, z = ");
  scanf("%d%d%d", &x, &y, &z);
  
  printf("largest = %d\n", max_3_int(&x, &y, &z));
  printf("smallest = %d\n", min_3_int(&x, &y, &z));
  
  return 0;
  
}