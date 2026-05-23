/* Input n integers and find the second largest number without sorting.
 input n, arr[n]
 print the array
 find maximum
 print the array, without max
 find the max of arr (max2)
 OUTPUT : max2 of arr
 */

#include <stdio.h>
int main() {
  int n;
  
  printf("Enter number of elements: "); // n input
  scanf("%d", &n);
  
  int arr[n];
  
  printf("Enter %d elements: ", n); // arr1 input
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  printf("the array : \n"); // print arr1
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n");
  
  int max = arr[0];
  
  for(int i = 0; i < n; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
  }
  
  printf("array without max1 : \n");
  for(int i=0; i < n; i++) {
    if(arr[i] == max) 
      continue;
    printf("%d ", arr[i]); 
  }
  
  printf("\n");
  
  int max2 = arr[0];
  
  for(int i = 0; i < n; i++) {
    if(arr[i] > max2 && arr[i] != max) {
      max2 = arr[i];
    }
  }
  
  printf("2nd max = %d", max2);
  
  return 0;
}