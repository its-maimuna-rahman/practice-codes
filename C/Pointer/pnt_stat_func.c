#include <stdio.h>
#include <math.h>

//---------*bubble sort--------
void sort(double *arr, int n) {
  double temp = 0;
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(*(arr + j) > *(arr + j + 1)) {
        temp = *(arr + j);
        *(arr + j) = *(arr + j + 1);
        *(arr + j + 1) = temp;
      }
    }
  }  
}


//-----------0.sum-----------
double sum(double *arr, int n) {
  double total = 0;
  for (int i = 0; i < n; i++) {
    total += *(arr + i);  // using pointer to access each element
  }
  return total;
}


//--------1.average---------
double average(double *arr, int n) {
  double s = sum(arr, n);
  return s / n;
  
}

//--------2. median--------
double median(double *arr, int n) {
  sort(arr, n);
  if(n % 2 == 0) {
    return (*(arr + (n/2) - 1) + *(arr + (n/2))) / 2;
  }
  else {
    return *(arr + (n/2));
  }
  
}

//---------- 3,4. minimum and maximum-------------
void min_max(double *arr, int n, double *min, double *max) {
  sort(arr, n);
  *min = *(arr + 0);
  *max = *(arr + n - 1);
}

//-------- 5.mean deviation (population) ---------
double mean_deviation(double *arr, int n) {
  double sum_diff = 0;
  double mean = average(arr, n);
  for(int i = 0; i < n; i++) {
    sum_diff += fabs(*(arr+i) - mean);
  }
  return sum_diff / n;
}


// --------6.variance (population)--------
double variance(double *arr, int n) {
  double sum_sq  = 0;
  double mean = average(arr, n);
  for(int i = 0; i < n; i++) {
    sum_sq += (*(arr+i) - mean) * (*(arr+i) - mean);
  }
  return sum_sq / n;
}

// ---------7.standard deviation----------
double standard_deviation(double *arr, int n) {
  double var = variance(arr, n);
  return sqrt(var);
}

// ---------8.coefficient of variation-------------
double coefficient_of_variation(double *arr, int n) {
  double mean = average(arr, n);
  double sd = standard_deviation(arr, n);
  return (sd / mean) * 100;
}

// ----------------9, 10, 11.quartiles--------------------
void quartiles(double *arr, int n, double *q1, double *q2, double *q3) {
  sort(arr, n);
  
  *q2 = median(arr, n);
  int mid = n/2;
  if(n % 2 == 0) {
    *q1 = median(arr, mid);
    *q3 = median(arr + mid, mid);
  }
  else {
    *q1 = median(arr, mid);
    *q3 = median(arr + mid + 1, mid);
  }
}

// ------------12.iqr-----------------
double iqr(double *arr, int n) {
  double q1, q2, q3;
  quartiles(arr, n, &q1, &q2, &q3);
  return (q3 - q1);
}
