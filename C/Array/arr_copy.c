#include <stdio.h>
int main() {
  
  int n, i=0, j=0;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  int arr1[n];
  
  printf("Enter %d elements: ", n); 
  for(int i = 0; i < n; i++) { // array input
    scanf("%d", &arr1[i]);
  }
  
  printf("original :\n");
  for(int i = 0; i < n; i++) { // printing input (og)
    printf("%d ", arr1[i]);
  }
  
  printf("\n");
  
  int arr2[n];
  
  for(int i = 0; i < n; i++) { // coping array
    arr2[i] = arr1[i]; 
  }
  
  printf("copied :\n");
  for(int i = 0; i < n; i++) { // printing input (og)
    printf("%d ", arr2[i]);
  }
  
  return 0;
}