#include <stdio.h>
int main() {
  
  int n;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  int arr[n];
  
  printf("Enter %d elements: ", n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  printf("before reverse :\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  printf("after reverse :\n");
  for(int i = n-1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}