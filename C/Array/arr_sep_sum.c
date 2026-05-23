/* sum of positive and negative num separately using array
 input n, input array
 if arr[i] > 0 : s=s+arr[i]
 if arr[i] < 0 : t=t+arr[i]
 if arr[i] = 0 : print invalid
 print s, print t separately
 */

#include <stdio.h>
int main() {
  int n;
  
  printf("enter number of elements n = ");
  scanf("%d", &n);
  
  int arr[n];
  
  printf("enter %d elements = \n", n);
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  int s=0, t=0;
  
  for(int i=0; i<n; i++) {
    if(arr[i] > 0) {
      s=s+arr[i];
    }
    if(arr[i] < 0) {
      t=t+arr[i];
    }
    if(arr[i] == 0) {
      printf("0 is invalid input\n");
    }
  }
  
  printf("sum of positive nums = %d\n", s);
  printf("sum of negative nums = %d\n", t);
  
  
  return 0;
}