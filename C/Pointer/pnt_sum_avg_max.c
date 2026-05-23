#include <stdio.h>

//function using pointer
// as 1 function giving 3 output

void func(double arr[], int n, double *sum, double *avg, double *max) {
  double *s = 0;
  *max = arr[0];
  
  for(int i = 0; i < n; i++) {
    *sum += arr[i];
    if(arr[i] > *max) {
      *max = arr[i];
    }
  }
  
  *avg = *sum / n;
  
}

int main() {
  int n;
  double s, a, m;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  double arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }
  
  func(arr, n, &s, &a, &m);
  
  printf("sum = %.2lf\n", s);
  printf("average = %.2lf\n", a);
  printf("maximum = %.2lf\n", m);
  
  return 0;
}
