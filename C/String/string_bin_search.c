// use binary search to find index of a string
// binary search only works for sorted array
//the elements of the array should not repeat.

#include <stdio.h>
#include <string.h>

void sort_str(char str[][100], int n) {
  for(int i = 0; i < n - 1; i++ ) {
    for(int j = 0; j < n - i - 1; j++) {
      char temp[100];
      if(strcmp(str[j], str[j+1]) > 0) {
        strcpy(temp, str[j]);
        strcpy(str[j], str[j+1]);
        strcpy(str[j+1], temp);
      }
    }
  }
}

int binary_search(char arr[][100], int n, char key[]) {
    int low = 0, high = n - 1;
    for(int i = 0; i < n; i++) {
        int mid = (high + low) / 2;
    
        if(strcmp(arr[mid], key) == 0) {
          return mid;
        }
        else if(strcmp(arr[mid], key) < 0) {
          low = mid + 1;
        }
        else {
          high = mid - 1;
        }
    }
  
    return -1;
}

int main() {
  int n;
  
  printf("Enter number of strings: ");
  scanf("%d", &n);
  
  char str[n][100];
  
  printf("Enter %d strings:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
  }
  
  sort_str(str, n);
  
  printf("\nSorted strings:\n");
  for(int i = 0; i < n; i++) {
    printf("%s\n", str[i]);
  }
  
  char search[100];
  int result;
  
  printf("enter string for binary search = ");
  scanf(" %s", &search);
  
  result = binary_search(str, n, search);
  
  if(result != -1) {
    printf("found at index = %d\n", result);
  }
  else {
    printf("not found\n");
  }
  
  return 0;
}    