// binary search for repeated elements of an array.
// shows first and last index

#include <stdio.h>

void sort(int arr[], int n) {
  int temp = 0;
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }  
}


int first_index(int arr[], int n, int key) {
  int low = 0, high = n - 1, ans = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    
    if (arr[mid] == key) {
      ans = mid;
      high = mid - 1;
    }
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  
  return ans;
}


int last_index(int arr[], int n, int key) {
  int low = 0, high = n - 1, ans = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    
    if (arr[mid] == key) {
      ans = mid;
      low = mid + 1;
    }
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  
  return ans;
}

int main() {
  int n, key;
  
  printf("Enter number of elements = ");
  scanf("%d", &n);
  
  int arr[n];
  
  printf("Enter elements = \n");
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  sort(arr, n);
  
  printf("The sorted array = \n");
  for(int i = 0; i < n; i++) {
    printf("%d  ", arr[i]);
  }
  
  printf("\n");
  printf("Enter a element to search = ");
  scanf(" %d", &key);

  int first = first_index(arr, n, key);
  int last  = last_index(arr, n, key);
  
  printf("First occurrence = %d\n", first);
  printf("Last occurrence  = %d\n", last);
  
  return 0;
}
