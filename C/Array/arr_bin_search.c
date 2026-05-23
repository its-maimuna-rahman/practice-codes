// as binary search only works for sorted array, the program first will sort
// the array then will work with the new sorted array
//the elements of the array should not repeat.

#include <stdio.h>

void sort(int arr[], int n) {
  int temp = 0;
  
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int binary_search(int arr[], int n, int key) {
  int low = 0, high = n - 1;
  
  while(low <= high) {
    int mid = (high + low) / 2;
    
    if(arr[mid] == key) 
      return mid;             //found
    else if(arr[mid] < key) 
      low = mid + 1;          // go right
    else
      high = mid - 1;         // go left
  }
  
  return -1;                      // not found                
}

int main() {
  int n, search;
  
  printf("Enter number of elements = ");
  scanf("%d", &n);
  
  int x[n];
  
  printf("Enter elements (unrepeated) = \n");
  for(int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  
  sort(x, n);
  
  printf("The sorted array = \n");
  for(int i = 0; i < n; i++) {
    printf("%d  ", x[i]);
  }
  
  printf("\n");
  printf("Enter a element to search = ");
  scanf(" %d", &search);
  
  int answer = binary_search(x, n, search);
  
  if(answer != -1) {
    printf("the index of %d is = %d\n", search, answer);
  }
  else {
    printf("element not found");
  }
  
  return 0;
} 