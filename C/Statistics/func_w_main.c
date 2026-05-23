// mode and sk1 will work properly if the array is unimodal.
// other statistics don't have any condition

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//------- * bubble sort --------
void sort(double arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        double temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
} 


// -------- 0. sum ---------------
double sum(double array[], int n) {
  
  double sum = 0;
  for(int i = 0; i < n; i++) {
    sum = sum + array[i];
  }
  return sum;
}

// --------- 1. average ------------
double average(double array[], int n) {
  
  double sum = 0;
  for(int i = 0; i < n; i++) {
    sum = sum + array[i];
  }
  double avg = sum/n;
  return avg;
}

// ----------- 2. median -----------
double median(double arr[], int n) {
  sort(arr, n);
  double median;
  
  if(n % 2 != 0) {
    median = arr[n/2];
  }
  if(n % 2 == 0) {
    median = (arr[(n/2) - 1] + arr[n/2]) / 2;
  }
  
  return median;
}

// ------------ 3. mode -------------
double mode(double arr[], int n) {
  int maxCount = 0;
  double modeValue = arr[0];
  
  for (int i = 0; i < n; i++) {
    int count = 0;
    
    // Count occurrences of arr[i]
    for (int j = 0; j < n; j++) {
      if (arr[j] == arr[i]) {
        count++;
      }
    }
    // Update mode if a higher count is found
    if (count > maxCount) {
      maxCount = count;
      modeValue = arr[i];
    }
  }
  return modeValue;
}

//------------ 4. mean deviation -------------------
double mean_deviation(double arr[], int n) {
  double m_d, temp = 0;
  sort(arr, n);
  double mean = average(arr, n);
  
  for(int i = 0; i < n; i++) {
    temp += fabs(arr[i] - mean);
  }
  m_d = temp / n;
  return m_d;
}

//---------- 5. variance ----------------
double variance(double arr[], int n) {
  double var, temp = 0;
  sort(arr, n);
  double mean = average(arr, n);
  
  for(int i = 0; i < n; i++) {
    temp += ((arr[i] - mean) * (arr[i] - mean));
  }
  var = temp / n;
  return var;
}

// ----------- 6. standard_deviation ---------------
double standard_deviation(double arr[], int n) {
  double sd, temp1 = 0, temp2 = 0;
  sort(arr, n);
  double mean = average(arr, n);
  
  for(int i = 0; i < n; i++) {
    temp1 += ((arr[i] - mean) * (arr[i] - mean));
  }
  temp2 = temp1 / n;
  sd = sqrt(temp2);
  return sd;
}

// ----------- 7. coefficient of variation -----------------
double coefficient_of_variation(double arr[], int n) {
  double cv, sd, mean;
  sort(arr, n);
  sd = standard_deviation(arr, n);
  mean = average(arr, n);
  cv = (sd / mean) * 100;
  return cv;
}

//----- 8,9,10. quartiles (pointer because output is more than 1) --------
void quartiles(double arr[], int n, double *q1, double *q2, double *q3) {
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

//------------ 11. IQR ----------------
double iqr(double arr[], int n) {
  double q1, q2, q3, iqr;
  quartiles(arr, n, &q1, &q2, &q3);
  iqr = q3 - q1;
  return iqr;
}

// ----------- 12. quartile deviation ----------
double quartile_deviation(double arr[], int n) {
  double qd;
  qd = iqr(arr, n);
  return qd / 2;
}

// ---------- 13, 14, 15, 16 raw moments -----------------
double raw_moment(double arr[], int n, int r) {
  double mr = 0;
  for(int i = 0; i < n; i++) {
    mr += pow(arr[i], r);
  }
  return mr / n;
  
}

//--------- 17, 18, 19, 20 central moments about mean ----------
double central_moment(double arr[], int n, int r) {
  double mc = 0;
  double mean = average(arr, n);
  for(int i = 0; i < n; i++) {
    mc += pow((arr[i] - mean), r);
  }
  return mc / n;
  
}

// --------- 21. pearson 1st coefficient of skewness ----------
double pearson_sk1(double arr[], int n) {
  double mean, mod, sd;        
  mean = average(arr, n);
  mod = mode(arr, n);
  sd = standard_deviation(arr, n);
  return (mean - mod) / sd;
  
}

// -------- 22. pearson 2nd coefficient of skewness -----------
double pearson_sk2(double arr[], int n) {
  double mean, med, sd;
  mean = average(arr, n);
  med = median(arr, n);
  sd = standard_deviation(arr, n);
  return (3 * (mean - med)) / sd;
  
}

// --------- 23. gamma 1 -------------
double gamma1(double arr[], int n) {
  double mc3, mc2, g1;
  mc2 = central_moment(arr, n, 2);
  mc3 = central_moment(arr, n, 3);
  g1 = mc3 / pow(mc2, (1.5));
  return g1;
  
}

// --------- 24. beta 1 -------------
double beta1(double arr[], int n) {
  double g1;
  g1 = gamma1(arr, n);
  return g1*g1;
}

// --------- 25. beta 2 ------------
double beta2(double arr[], int n) {
  double mc4, mc2, b2;
  mc2 = central_moment(arr, n, 2);
  mc4 = central_moment(arr, n, 4);
  b2 = mc4 / pow(mc2, 2);
  return b2;
}

// ------- 26. gamma 2 -------------
double gamma2(double arr[], int n) {
  double b2;
  b2 = beta2(arr, n);
  return b2 - 3;
}

//summary of statistics
void summary_stat(double *arr, int n, double *result) {
  double q1, q2, q3;
  result[0] = sum(arr, n);
  result[1] = average(arr, n);
  result[2] = median(arr, n);
  result[3] = mode(arr, n);
  result[4] = mean_deviation(arr, n);
  result[5] = variance(arr, n);
  result[6] = standard_deviation(arr, n);
  result[7] = coefficient_of_variation(arr, n);
  quartiles(arr, n, &q1, &q2, &q3);
  result[8] = q1;
  result[9] = q2;
  result[10] = q3;
  result[11] = iqr(arr, n);
  result[12] = quartile_deviation(arr, n);
  result[13] = raw_moment(arr, n, 1);
  result[14] = raw_moment(arr, n, 2);
  result[15] = raw_moment(arr, n, 3);
  result[16] = raw_moment(arr, n, 4);
  result[17] = central_moment(arr, n, 1);
  result[18] = central_moment(arr, n, 2);
  result[19] = central_moment(arr, n, 3);
  result[20] = central_moment(arr, n, 4);
  result[21] = pearson_sk1(arr, n);
  result[22] = pearson_sk2(arr, n);
  result[23] = gamma1(arr, n);
  result[24] = beta1(arr, n);
  result[25] = gamma2(arr, n);
  result[26] = beta2(arr, n);
}
  
//main function
int main() {
  int n;
  
  printf("Enter number of elements, n = ");
  scanf("%d", &n);
  
  double arr[n];
  
  for(int i=0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }
  
  double result[35];
  summary_stat(arr, n, result);
  
  printf("\ntotal = %.3lf\n", result[0]);
  printf("average = %.3lf\n", result[1]);
  printf("median = %.3lf\n", result[2]);
  printf("mode = %.3lf\n", result[3]);
  printf("mean deviation = %.3lf\n", result[4]);
  printf("variance = %.3lf\n", result[5]);
  printf("standard deviation = %.3lf\n", result[6]);
  printf("coefficient_of_variation = %.3lf\n", result[7]);
  printf("q1 = %.3lf\n", result[8]);  // pointers
  printf("q2 = %.3lf\n", result[9]);
  printf("q3 = %.3lf\n", result[10]);
  printf("iqr = %.3lf\n", result[11]);
  printf("quartile deviation = %.3lf\n", result[12]);
  printf("1st raw moment = %.3lf\n", result[13]);
  printf("2nd raw moment = %.3lf\n", result[14]);
  printf("3rd raw moment = %.3lf\n", result[15]);
  printf("4th raw moment = %.3lf\n", result[16]);
  printf("1st central moment = %.3lf\n", result[17]);
  printf("2nd central moment = %.3lf\n", result[18]);
  printf("3rd central moment = %.3lf\n", result[19]);
  printf("4th central moment = %.3lf\n", result[20]);
  printf("pearson's 1st coefficient of skewness = %.3lf\n", result[21]);
  printf("pearson's 2nd coefficient of skewness = %.3lf\n", result[22]);
  printf("gamma 1 = %.3lf\n", result[23]);
  printf("beta 1 = %.3lf\n", result[24]);
  printf("gamma 2 = %.3lf\n", result[25]);
  printf("beta 2 = %.3lf\n", result[26]);
  
  return 0;
}
