#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// ===== ORIGINAL DATA FUNCTIONS =====
double average(double arr[], int n);
double variance(double arr[], int n);
double standard_deviation(double arr[], int n);
double raw_moment(double arr[], int n, int r);
double central_moment(double arr[], int n, int r);
double median(double arr[], int n);
double mode(double arr[], int n);
double geometric_mean(double arr[], int n);
double harmonic_mean(double arr[], int n);
double weighted_mean(double arr[], double weights[], int n);
double minimum(double arr[], int n);
double maximum(double arr[], int n);
double quartile(double arr[], int n, int q);
double mean_deviation(double arr[], int n);
double iqr(double arr[], int n);
double quartile_deviation(double arr[], int n);
double coefficient_of_variation(double arr[], int n);

// ===== HELPER FUNCTIONS =====
int compare_doubles(const void *a, const void *b) {
  return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

// ===== ORIGINAL DATA STATISTICS =====
double average(double arr[], int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum / n;
}

double variance(double arr[], int n) {
  double mean = average(arr, n);
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (arr[i] - mean) * (arr[i] - mean);
  }
  return sum / n;
}

double standard_deviation(double arr[], int n) {
  return sqrt(variance(arr, n));
}

double raw_moment(double arr[], int n, int r) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pow(arr[i], r);
  }
  return sum / n;
}

double central_moment(double arr[], int n, int r) {
  double mean = average(arr, n);
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pow(arr[i] - mean, r);
  }
  return sum / n;
}

double median(double arr[], int n) {
  double temp[n];
  memcpy(temp, arr, sizeof(double) * n);
  qsort(temp, n, sizeof(double), compare_doubles);
  
  if (n % 2 == 0) {
    return (temp[n/2 - 1] + temp[n/2]) / 2.0;
  }
  return temp[n/2];
}

double mode(double arr[], int n) {
  double temp[n];
  memcpy(temp, arr, sizeof(double) * n);
  qsort(temp, n, sizeof(double), compare_doubles);
  
  double max_val = temp[0];
  int max_count = 1;
  double current_val = temp[0];
  int current_count = 1;
  
  for (int i = 1; i < n; i++) {
    if (fabs(temp[i] - current_val) < 1e-10) {
      current_count++;
    } else {
      if (current_count > max_count) {
        max_count = current_count;
        max_val = current_val;
      }
      current_val = temp[i];
      current_count = 1;
    }
  }
  
  if (current_count > max_count) {
    max_val = current_val;
  }
  
  return max_val;
}

double geometric_mean(double arr[], int n) {
  double product = 1.0;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= 0) return NAN;
    product *= arr[i];
  }
  return pow(product, 1.0 / n);
}

double harmonic_mean(double arr[], int n) {
  double sum_reciprocal = 0.0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) return NAN;
    sum_reciprocal += 1.0 / arr[i];
  }
  return n / sum_reciprocal;
}

double weighted_mean(double arr[], double weights[], int n) {
  double weighted_sum = 0.0;
  double weight_sum = 0.0;
  
  for (int i = 0; i < n; i++) {
    weighted_sum += arr[i] * weights[i];
    weight_sum += weights[i];
  }
  
  return weighted_sum / weight_sum;
}

double minimum(double arr[], int n) {
  double min_val = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min_val) min_val = arr[i];
  }
  return min_val;
}

double maximum(double arr[], int n) {
  double max_val = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max_val) max_val = arr[i];
  }
  return max_val;
}

double quartile(double arr[], int n, int q) {
  if (q < 0 || q > 4) return NAN;
  
  double temp[n];
  memcpy(temp, arr, sizeof(double) * n);
  qsort(temp, n, sizeof(double), compare_doubles);
  
  if (q == 0) return temp[0];
  if (q == 4) return temp[n-1];
  
  double position = (q / 4.0) * (n - 1);
  int lower = (int)position;
  int upper = lower + 1;
  double fraction = position - lower;
  
  if (upper >= n) return temp[n-1];
  
  return temp[lower] * (1 - fraction) + temp[upper] * fraction;
}

double mean_deviation(double arr[], int n) {
  double mean = average(arr, n);
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += fabs(arr[i] - mean);
  }
  return sum / n;
}

double iqr(double arr[], int n) {
  return quartile(arr, n, 3) - quartile(arr, n, 1);
}

double quartile_deviation(double arr[], int n) {
  return iqr(arr, n) / 2.0;
}

double coefficient_of_variation(double arr[], int n) {
  double mean = average(arr, n);
  double std_dev = standard_deviation(arr, n);
  
  if (mean == 0) return NAN;
  return (std_dev / fabs(mean)) * 100.0;
}

// ===== ORIGIN AND SCALE CHANGE FUNCTIONS =====
// Transformation: y = a + bx (a = origin, b = scale)

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
  double min_val = minimum(arr, n);
  return a + (b * min_val);
}

double maximum_change(double arr[], int n, double a, double b) {
  double max_val = maximum(arr, n);
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

// ===== MAIN PROGRAM =====
int main(void) {
  int n, r, q;
  double a, b;
  
  printf("\n\n============== UNIVARIATE STATISTICAL ANALYSIS WITH ORIGIN/SCALE SHIFT =============\n\n");
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  double arr[n];
  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }
  
  // Weights for weighted mean
  double weights[n];
  printf("\nEnter weights for weighted mean:\n");
  for (int i = 0; i < n; i++) {
    scanf("%lf", &weights[i]);
  }
  
  printf("\n======================== TRANSFORMATION =======================\n");
  printf("Transformation: Y = a + bX\n\n");
  printf("Enter origin change (a): ");
  scanf("%lf", &a);
  printf("Enter scale change (b): ");
  scanf("%lf", &b);
  
  // ===== LOCATION STATISTICS =====
  printf("\n\n==================== LOCATION STATISTICS ======================\n");
  printf("%-30s %15s %15s\n", "Statistic", "Original", "Transformed");
  printf("%-30s %15s %15s\n", "-----", "--------", "-----");
  printf("%-30s %15.3lf %15.3lf\n", "Mean", average(arr, n), mean_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Median", median(arr, n), median_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Mode", mode(arr, n), mode_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Geometric Mean", geometric_mean(arr, n), geometric_mean_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Harmonic Mean", harmonic_mean(arr, n), harmonic_mean_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Weighted Mean", weighted_mean(arr, weights, n), weighted_mean_change(arr, weights, n, a, b));
  
  // ===== EXTREMES =====
  printf("\n======================= EXTREME VALUES ========================\n");
  printf("%-30s %15s %15s\n", "Statistic", "Original", "Transformed");
  printf("%-30s %15s %15s\n", "-----", "--------", "-----");
  printf("%-30s %15.3lf %15.3lf\n", "Minimum", minimum(arr, n), minimum_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Maximum", maximum(arr, n), maximum_change(arr, n, a, b));
  
  // ===== QUARTILES =====
  printf("\n========================== QUARTILES ==========================\n");
  printf("%-30s %15s %15s\n", "Quartile", "Original", "Transformed");
  printf("%-30s %15s %15s\n", "-----", "--------", "-----");
  printf("%-30s %15.3lf %15.3lf\n", "Q0 (Min)", quartile(arr, n, 0), quartile_change(arr, n, 0, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Q1 (25%)", quartile(arr, n, 1), quartile_change(arr, n, 1, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Q2 (Median)", quartile(arr, n, 2), quartile_change(arr, n, 2, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Q3 (75%)", quartile(arr, n, 3), quartile_change(arr, n, 3, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Q4 (Max)", quartile(arr, n, 4), quartile_change(arr, n, 4, a, b));
  
  // ===== DISPERSION STATISTICS =====
  printf("\n================= DISPERSION STATISTICS =======================\n");
  printf("%-30s %15s %15s\n", "Statistic", "Original", "Transformed");
  printf("%-30s %15s %15s\n", "-----", "--------", "-----");
  printf("%-30s %15.3lf %15.3lf\n", "Variance", variance(arr, n), variance_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Std Deviation", standard_deviation(arr, n), standard_deviation_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Mean Deviation", mean_deviation(arr, n), mean_deviation_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "IQR", iqr(arr, n), iqr_change(arr, n, a, b));
  printf("%-30s %15.3lf %15.3lf\n", "Quartile Deviation", quartile_deviation(arr, n), quartile_deviation_change(arr, n, a, b));
  printf("%-30s %15.3lf%% %14.3lf%%\n", "Coefficient of Variation", coefficient_of_variation(arr, n), coefficient_of_variation_change(arr, n, a, b));
  
  // ===== MOMENTS =====
  printf("\n========================= RAW MOMENTS =========================\n");
  printf("%-30s %15s %15s\n", "Moment Order", "Original", "Transformed");
  printf("%-30s %15s %15s\n", "-----", "--------", "-----");
  for (int i = 1; i <= 4; i++) {
    char label[50];
    sprintf(label, "Raw Moment (r=%d)", i);
    printf("%-30s %15.3lf %15.3lf\n", label, raw_moment(arr, n, i), raw_moment_change(arr, n, i, a, b));
  }
  
  printf("\n======================= CENTRAL MOMENTS =======================\n");
  printf("%-30s %15s %15s\n", "Moment Order", "Original", "Transformed");
  printf("%-30s %15s %15s\n", "-----", "--------", "-----");
  for (int i = 1; i <= 4; i++) {
    char label[50];
    sprintf(label, "Central Moment (r=%d)", i);
    printf("%-30s %15.3lf %15.3lf\n", label, central_moment(arr, n, i), central_moment_change(arr, n, i, a, b));
  }
  
  printf("\n===========================================================================\n");
  
  return 0;
}