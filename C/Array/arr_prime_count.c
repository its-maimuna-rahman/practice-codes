/*Count how many elements of the array are prime numbers.
 */

#include <stdio.h>
int main() {
  int n,num, s=0;
  
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
  
  for(int i = 0; i < n; i++) {
    num = arr[i];
    if(num <= 1)
      continue;
    
    int isPrime = 1;    
    for(int j=2; j <= (num/2); j++) {
      if(num % j == 0) {
        isPrime=0;
        break;
      }
    }
    if(isPrime) {
      s++;
    }
  }
  
  
  printf("total prime num = %d", s);
  
  
  return 0;
}    