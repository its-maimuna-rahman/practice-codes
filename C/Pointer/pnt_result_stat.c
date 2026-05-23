//Write one C function (summary_stat) using a pointer which will return all
//these outputs

#include <stdio.h>
#include <math.h>

// Declare all the functions from stats.c
double sum(double *arr, int n);
double average(double *arr, int n);
double median(double *arr, int n);
double min_max(double *arr, int n, double *min, double *max);
double mean_deviation(double *arr, int n);
double variance(double *arr, int n);  
double standard_deviation(double *arr, int n);
double coefficient_of_variation(double *arr, int n);
double quartiles(double *arr, int n, double *q1, double *q2, double *q3);
double iqr(double *arr, int n);

  
  
void summary_statistics(double *arr, int n, double *results) {
  double q1, q2, q3;
  double min, max;
  
  results[0] = sum(arr, n);
  results[1] = average(arr, n);
  results[2] = median(arr, n);
  min_max(arr, n, &min, &max);
  results[3] = min;
  results[4] = max;
  results[5] = mean_deviation(arr, n);
  results[6] = variance(arr, n);
  results[7] = standard_deviation(arr, n);
  results[8] = coefficient_of_variation(arr,n);
  quartiles(arr, n, &q1, &q2, &q3);
  results[9] = q1;
  results[10] = q2;
  results[11] = q3;
  results[12] = iqr(arr, n);
}


int main(void) {
  int n;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  double arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }
  
  double results[12];
  summary_statistics(arr, n, results);
  
  printf("\nsum = %.3lf\n", results[0]);
  printf("average = %.3lf\n", results[1]);
  printf("median = %.3lf\n", results[2]);
  printf("minimum = %.3lf\n", results[3]);
  printf("maximum = %.3lf\n", results[4]);
  printf("mean deviation = %.3lf\n", results[5]);
  printf("variance = %.3lf\n", results[6]);
  printf("standard deviation = %.3lf\n", results[7]);
  printf("coeffitient of variation = %.3lf\n", results[8]);
  printf("1st quartile, q1 = %.3lf\n", results[9]);
  printf("2st quartile, q2 = %.3lf\n", results[10]);
  printf("3st quartile, q3 = %.3lf\n", results[11]);
  printf("inter quartile range, IQR = %.3lf\n", results[12]);
  
  return 0;
}