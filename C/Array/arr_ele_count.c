// Count how many times each number appears in the array.

#include <stdio.h>
int main() {
  int n, s=1, num1, num2;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  int arr[n];
  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  printf("The array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  int visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = 0; // 0 means not counted yet (input)
  }
  
  for (int i = 0; i < n; i++) {
    if(visited[i] == 1) {
      continue; // skip already counted numbers
    }
    
    s=1; // reset count
    for(int j = i+1; j < n; j++) {
      if(arr[i] == arr[j]) {
        s=s+1;
        visited[j] = 1; // mark duplicate as counted
      }
    }
    printf("count of %d = %d\n", arr[i], s);
  } 
  return 0;
} 
