/*Remove duplicates from an array and print the new array.
 input n, arr[n]
 print arr
 for loop, if arr[i] != arr[i+1], print arr[1]
 */

#include <stdio.h>
int main() {
  int n;
  
  printf("Enter number of elements: "); // enter num of elements of array
  scanf("%d", &n);
  
  int arr[n];
  printf("Enter %d elements: ", n); // scan array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  printf("The array:\n");
  for (int i = 0; i < n; i++) {    // print the array
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) { // bubble sort
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  for (int i = 0; i < n - 1; i++) { // remove duplicate
    if(arr[i] != arr[i+1]) {
      printf("%d ", arr[i]);
    }
  }
  printf("%d\n", arr[n - 1]);
  
  return 0;
}    