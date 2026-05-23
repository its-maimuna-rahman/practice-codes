#include <stdio.h>
int main () {
  int n, s=0;
  
  printf("enter number of elements = ");
  scanf("%d", &n);
  
  int arr[n];
  
  printf("enter %d elements = " ,n); // sum
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
    s=s+arr[i];
  }
  
  printf("sum = %d", s);
  
  return 0;
}