/* Input an array and a number, print its index (or “Not found”).
 */

#include <stdio.h>
int main() {
  int n,x;
  
  printf("enter number of elements n = ");
  scanf("%d", &n);
  
  int arr[n];
  
  printf("enter %d elements = \n", n);
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  printf("elements : \n");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n");
  
  printf("enter a num to search = ");
  scanf("%d", &x);
  
  for(int i=0; i<n; i++) {
    if(arr[i] == x) {
      printf("number found at index %d\n", i+1);
    }
  }
  
  return 0;
}