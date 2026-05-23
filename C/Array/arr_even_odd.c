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
  
  int even = 0;
  int odd = 0;
  
  for(int i = 0; i < n; i++) {
    if(arr[i] != 0) {
      
      if(arr[i] % 2 == 0){
        even += 1; 
      }
      else {
        odd +=1;
      }
    }
    else {
      printf("0 is invalid\n");
    }
  }        
  
  printf("even = %d\n", even);
  printf("odd = %d", odd);
  
  return 0;
}