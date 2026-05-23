#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// ======== bubble sort ===========
void sort(double arr[], int n) {
  double temp = 0;
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

// ======== bubble sort for string ========
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

//========= binary search =============
int binary_search(double arr[], int n, double key) {
  int low = 0, high = n - 1;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] < key) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

// ======= binary search for string =========
int binary_search_str(char arr[][100], int n, char key[]) {
  int low = 0, high = n - 1;
  while(low <= high) { // Changed for loop to while
    int mid = low + (high - low) / 2;
    int res = strcmp(arr[mid], key);
    if(res == 0) return mid;
    else if(res < 0) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

// ========== 1. sum ===============
double sum(double arr[], int n) {
  double s = 0;
  for(int i = 0; i < n; i++) s += arr[i];
  return s;
}

// ======== 2. average/mean ==========
double average(double arr[], int n) {
  return sum(arr, n) / n;
}

// ========== 3. median ==============
double median(double arr[], int n) {
  sort(arr, n);
  if(n % 2 == 0) return (arr[n/2 - 1] + arr[n/2]) / 2.0;
  else return arr[n/2];
}

// ========= 4. mode ==============
double mode(double arr[], int n) {
  sort(arr, n);
  double mode_val = arr[0];
  int max_count = 1, current_count = 1;
  
  for(int i = 1; i < n; i++) {
    if(arr[i] == arr[i - 1]) {
      current_count++;
    } else {
      if(current_count > max_count) {
        max_count = current_count;
        mode_val = arr[i - 1];
      }
      current_count = 1;
    }
  }
  // Final check for the last element group
  if(current_count > max_count) {
    mode_val = arr[n - 1];
  }
  return mode_val;
}

// ========= 5. geometric mean ================== 
double geometric_mean(double arr[], int n) {
  double gm_sum = 0;
  for(int i = 0; i < n; i++) {
    gm_sum += log(arr[i]); 
  }
  return exp(gm_sum / n);
}

// ============ 6. harmonic mean ===============
double harmonic_mean(double arr[], int n) {
  double hm = 0;
  for(int i = 0; i < n; i++) hm += 1.0 / arr[i];
  return (double)n / hm;
}

// ========== 7. weighted mean ==============
double weighted_mean(double x[], double w[], int n) {
  double sx = 0, sw = 0, wm;
  for(int i = 0; i < n; i++) {
    sx += x[i] * w[i];
    sw += w[i];
  }
  if(sw == 0) {
    return 0;
  }
  return sx / sw;
}


// ============== 8. minimum ========================
double min(double arr[], int n) {
  sort(arr, n);
  return arr[0];
}

// ============== 9. maximum ========================
double max(double arr[], int n) {
  sort(arr, n);
  return arr[n - 1];
}

// =========== 10. mean deviation (sample) ==================
double mean_deviation(double arr[], int n) {
  double sum_diff = 0;
  double mean = average(arr, n);
  for(int i = 0; i < n; i++) {
    sum_diff += fabs(arr[i] - mean);
  }
  return sum_diff / (n-1);
}

// ============= 11. variance (sample) ====================
double variance(double arr[], int n) {
  double sum_sq  = 0;
  double mean = average(arr, n);
  for(int i = 0; i < n; i++) {
    sum_sq += ((arr[i] - mean) * (arr[i] - mean));
  }
  return sum_sq / (n-1);
}

// ========== 12. standard deviation ======================
double standard_deviation(double arr[], int n) {
  double var = variance(arr, n);
  return sqrt(var);
}

// ============ 13. coefficient of variation ==============
double coefficient_of_variation(double arr[], int n) {
  double mean = average(arr, n);
  double sd = standard_deviation(arr, n);
  return (sd / mean) * 100;
}

// ========== 14 quartile =====================
double quartile(double arr[], int n, int q_num) {
  sort(arr, n);
  
  if (q_num == 2) {
    return median(arr, n);
  }
  
  int mid = n / 2;
  
  if (q_num == 1) {
    return median(arr, mid);
  }
  
  if (q_num == 3) {
    if (n % 2 == 0) {
      return median(arr + mid, mid);
    }
    else {
      return median(arr + mid + 1, mid);
    }
  }
  
  return -1; // Return error if q_num is not 1, 2, or 3
}


// ============= 15. iqr ==================
double iqr(double arr[], int n) {
  double q1, q3;
  q1 = quartile(arr, n, 1);
  q3 = quartile(arr, n, 3);
  return (q3 - q1);
}

// ============ 16. quartile deviation ==============
double quartile_deviation(double arr[], int n) {
  double qd;
  qd = iqr(arr, n);
  return qd / 2;
}

// =========== 17 raw moments ==============
double raw_moment(double arr[], int n, int r) {
  double mr = 0;
  for(int i = 0; i < n; i++) {
    mr += pow(arr[i], r);
  }
  return mr / n;
  
}

//============= 18 central moments about mean ========
double central_moment(double arr[], int n, int r) {
  double mc = 0;
  double mean = average(arr, n);
  for(int i = 0; i < n; i++) {
    mc += pow((arr[i] - mean), r);
  }
  return mc / n;
  
}

// =========== 19. pearson 1st coefficient of skewness ===========
double pearson_sk1(double arr[], int n) {
  double mean, mod, sd;        
  mean = average(arr, n);
  mod = mode(arr, n);
  sd = standard_deviation(arr, n);
  return (mean - mod) / sd;
  
}

// ========= 20. pearson 2nd coefficient of skewness ============
double pearson_sk2(double arr[], int n) {
  double mean, med, sd;
  mean = average(arr, n);
  med = median(arr, n);
  sd = standard_deviation(arr, n);
  return (3 * (mean - med)) / sd;
  
}

// ========= 21. gamma 1 =============
double gamma1(double arr[], int n) {
  double mc3, mc2, g1;
  mc2 = central_moment(arr, n, 2);
  mc3 = central_moment(arr, n, 3);
  g1 = mc3 / pow(mc2, (1.5));
  return g1;
  
}

// =========== 22. beta 1 =============
double beta1(double arr[], int n) {
  double g1;
  g1 = gamma1(arr, n);
  return g1*g1;
}

// =========== 23. beta 2 ==============
double beta2(double arr[], int n) {
  double mc4, mc2, b2;
  mc2 = central_moment(arr, n, 2);
  mc4 = central_moment(arr, n, 4);
  b2 = mc4 / pow(mc2, 2);
  return b2;
}

// ========= 24. gamma 2 =============
double gamma2(double arr[], int n) {
  double b2;
  b2 = beta2(arr, n);
  return b2 - 3;
}

//=======  25. covariance (sample, that's why (n-1); if population needed, it's n)
double covariance(double x[], double y[], int n) {
  double mx = average(x, n);
  double my = average(y, n);
  double s = 0;
  
  for(int i = 0; i < n; i++) {
    s += (x[i] - mx) * (y[i] - my);
  }
  return s / (n-1);
} 

// ========== 26. coefficient of correlation =============
double r(double x[], double y[], int n) {
  double r;
  double mx = average(x, n);
  double my = average(y, n);
  double cov = 0, sx = 0, sy = 0;
  
  for(int i = 0; i < n; i++) {
    cov += (x[i] - mx) * (y[i] - my);
    sx += (x[i] - mx) * (x[i] - mx);
    sy += (y[i] - my) * (y[i] - my);
  }
  r = cov / sqrt(sx * sy);
  return r;
  
}

// ============ 27. beta (beta_1) for regression =================
double regression_beta1(double x[], double y[], int n) {
  double sum_xy = 0, sum_x = 0;                 // beta = cov(x,y) / var(x)
  double mx = average(x, n);
  double my = average(y, n);
  
  for(int i = 0; i < n; i++) {
    sum_xy += (x[i] - mx) * (y[i] - my);
    sum_x += (x[i] - mx) *(x[i] - mx);
  }
  return sum_xy / sum_x;
}

// ============= 28. alpha (beta_0) for regression =================
double regression_beta0(double x[], double y[], int n) {
  
  double mx = average(x, n);                  // beta0 = mean(y) - beta1*mean(x)
  double my = average(y, n);
  double beta1 = regression_beta1(x, y, n);
  
  return (my - (beta1 * mx)); 
}

//=============== 29. Coefficient of Determination =================
double R_square(double x[], double y[], int n) {
  double R = r(x, y, n);
  return (R * R);
}

// ===== ORIGIN AND SCALE CHANGE FUNCTIONS =====
// Transformation: y = a + bx (a = origin, b = scale)

// ===================== univariate ============================

double mean_change(double arr[], int n, double a, double b) {
  double mx = average(arr, n);
  return a + (b * mx);
}

double median_change(double arr[], int n, double a, double b) {
  double med = median(arr, n);
  return a + (b * med);
}

double mode_change(double arr[], int n, double a, double b) {
  double m = mode(arr, n);
  return a + (b * m);
}

double geometric_mean_change(double arr[], int n, double a, double b) {
  double gm = geometric_mean(arr, n);
  if (isnan(gm)) return NAN;
  return a + (b * gm);
}

double harmonic_mean_change(double arr[], int n, double a, double b) {
  double hm = harmonic_mean(arr, n);
  if (isnan(hm)) return NAN;
  return a + (b * hm);
}

double weighted_mean_change(double arr[], double weights[], int n, double a, double b) {
  double wm = weighted_mean(arr, weights, n);
  return a + (b * wm);
}

double minimum_change(double arr[], int n, double a, double b) {
  double min_val = min(arr, n);
  return a + (b * min_val);
}

double maximum_change(double arr[], int n, double a, double b) {
  double max_val = max(arr, n);
  return a + (b * max_val);
}

double quartile_change(double arr[], int n, int q, double a, double b) {
  double quart = quartile(arr, n, q);
  return a + (b * quart);
}

double variance_change(double arr[], int n, double a, double b) {
  double vx = variance(arr, n);
  return b * b * vx;
}

double standard_deviation_change(double arr[], int n, double a, double b) {
  double sdx = standard_deviation(arr, n);
  return fabs(b) * sdx;
}

double mean_deviation_change(double arr[], int n, double a, double b) {
  double md = mean_deviation(arr, n);
  return fabs(b) * md;
}

double iqr_change(double arr[], int n, double a, double b) {
  double iqr_val = iqr(arr, n);
  return fabs(b) * iqr_val;
}

double quartile_deviation_change(double arr[], int n, double a, double b) {
  double qd = quartile_deviation(arr, n);
  return fabs(b) * qd;
}

double coefficient_of_variation_change(double arr[], int n, double a, double b) {
  // CV is scale-invariant: CV(Y) = CV(X) if only scaling
  // But if origin changes, it affects CV
  double cv = coefficient_of_variation(arr, n);
  if (isnan(cv)) return NAN;
  
  double mean_y = a + (b * average(arr, n));
  double std_y = fabs(b) * standard_deviation(arr, n);
  
  if (mean_y == 0) return NAN;
  return (std_y / fabs(mean_y)) * 100.0;
}

double raw_moment_change(double arr[], int n, int r, double a, double b) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pow(a + b * arr[i], r);
  }
  return sum / n;
}

double central_moment_change(double arr[], int n, int r, double a, double b) {
  double mtx = central_moment(arr, n, r);
  return pow(b, r) * mtx;
}

// ===================== bivariate ============================

double covariance_change(double x[], double y[], int n, double a1, double b1, double a2, double b2) {
  // Cov(Y1, Y2) = b1*b2*Cov(X1, X2)
  // where Y1 = a1 + b1*X1 and Y2 = a2 + b2*X2
  double cov = covariance(x, y, n);
  return b1 * b2 * cov;
}

double regression_beta1_change(double x[], double y[], int n, double a1, double b1, double a2, double b2) {
  // Y = beta0 + beta1*X
  // (a2 + b2*y) = beta0 + beta1*(a1 + b1*x)
  // beta1_new = (b2/b1) * beta1_old
  double beta1_old = regression_beta1(x, y, n);
  if (isnan(beta1_old) || b1 == 0) return NAN;
  return (b2 / b1) * beta1_old;
}

double regression_beta0_change(double x[], double y[], int n, double a1, double b1, double a2, double b2) {
  // Y = beta0 + beta1*X
  // (a2 + b2*y) = beta0 + beta1*(a1 + b1*x)
  // beta0_new = a2 + b2*(beta0_old - b1*a1)
  double beta0_old = regression_beta0(x, y, n);
  if (isnan(beta0_old)) return NAN;
  return a2 + b2 * (beta0_old - b1 * a1);
}

