#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// ===== BIVARIATE FUNCTIONS =====
double average(double arr[], int n);
double variance(double arr[], int n);
double covariance(double arr1[], double arr2[], int n);
double regression_beta0(double x[], double y[], int n);
double regression_beta1(double x[], double y[], int n);

// ===== HELPER FUNCTIONS =====
int compare_doubles(const void *a, const void *b) {
  return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

// ===== BASIC STATISTICS =====
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

double covariance(double arr1[], double arr2[], int n) {
  double mean1 = average(arr1, n);
  double mean2 = average(arr2, n);
  double sum = 0;
  
  for (int i = 0; i < n; i++) {
    sum += (arr1[i] - mean1) * (arr2[i] - mean2);
  }
  
  return sum / n;
}

double regression_beta1(double x[], double y[], int n) {
  double cov = covariance(x, y, n);
  double var_x = variance(x, n);
  
  if (var_x == 0) return NAN;
  return cov / var_x;
}

double regression_beta0(double x[], double y[], int n) {
  double mean_x = average(x, n);
  double mean_y = average(y, n);
  double beta1 = regression_beta1(x, y, n);
  
  return mean_y - beta1 * mean_x;
}

// ===== ORIGIN AND SCALE CHANGE FUNCTIONS =====
// Transformation: y = a + bx (a = origin, b = scale)

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

// ===== MAIN PROGRAM =====
int main(void) {
  int n, choice;
  double a, b, a1, b1, a2, b2;
  
  printf("\n\n================ BIVARIATE STATISTICAL ANALYSIS WITH ORIGIN AND SCALE SHIFT ================\n\n");
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  double x[n], y[n];
  printf("Enter first dataset (X):\n");
  for (int i = 0; i < n; i++) {
    scanf("%lf", &x[i]);
  }
  
  printf("\nEnter second dataset (Y):\n");
  for (int i = 0; i < n; i++) {
    scanf("%lf", &y[i]);
  }
  
  printf("\n======================= TRANSFORMATION OPTIONS ==========================\n");
  printf("1. Same transformation for both datasets (Y = a + bX)\n");
  printf("2. Different transformations for two datasets\n");
  printf("Choose option (1-2): ");
  scanf("%d", &choice);
  
  if (choice == 1) {
    printf("\nEnter origin change (a): ");
    scanf("%lf", &a);
    printf("Enter scale change (b): ");
    scanf("%lf", &b);
    a1 = a;
    b1 = b;
    a2 = a;
    b2 = b;
  } else if (choice == 2) {
    printf("\nFor first dataset - Enter origin (a1): ");
    scanf("%lf", &a1);
    printf("For first dataset - Enter scale (b1): ");
    scanf("%lf", &b1);
    printf("For second dataset - Enter origin (a2): ");
    scanf("%lf", &a2);
    printf("For second dataset - Enter scale (b2): ");
    scanf("%lf", &b2);
  }
  
  // ===== DISPLAY ORIGINAL DATA =====
  printf("\n============================= ORIGINAL DATA ==============================\n");
  printf("%-10s %-15s %-15s\n", "Index", "X", "Y");
  printf("%-10s %-15s %-15s\n", "-----", "---", "---");
  for (int i = 0; i < n; i++) {
    printf("%-10d %-15.3lf %-15.3lf\n", i+1, x[i], y[i]);
  }
  
  // ===== BIVARIATE STATISTICS =====
  printf("\n========================= BIVARIATE STATISTICS ==========================\n");
  printf("%-30s %15s %15s\n", "Statistic", "Original", "Transformed");
  printf("%-30s %15s %15s\n", "-----", "--------", "-----");
  printf("%-30s %15.3lf %15.3lf\n", "Covariance", covariance(x, y, n), covariance_change(x, y, n, a1, b1, a2, b2));
  printf("%-30s %15.3lf %15.3lf\n", "Regression Beta0", regression_beta0(x, y, n), regression_beta0_change(x, y, n, a1, b1, a2, b2));
  printf("%-30s %15.3lf %15.3lf\n", "Regression Beta1", regression_beta1(x, y, n), regression_beta1_change(x, y, n, a1, b1, a2, b2));
  
  // ===== REGRESSION EQUATION =====
  printf("\n========================= REGRESSION EQUATIONS ==========================\n");
  double beta0_orig = regression_beta0(x, y, n);
  double beta1_orig = regression_beta1(x, y, n);
  double beta0_trans = regression_beta0_change(x, y, n, a1, b1, a2, b2);
  double beta1_trans = regression_beta1_change(x, y, n, a1, b1, a2, b2);
  
  printf("Original: Y = %.3lf + %.3lf*X\n", beta0_orig, beta1_orig);
  printf("Transformed: Y = %.3lf + %.3lf*X\n", beta0_trans, beta1_trans);
  
  if (choice == 2) {
    printf("\nTransformation Details:\n");
    printf("Dataset 1: Y1 = %.2lf + %.2lf*X1\n", a1, b1);
    printf("Dataset 2: Y2 = %.2lf + %.2lf*X2\n", a2, b2);
  } else {
    printf("\nTransformation: Y = %.2lf + %.2lf*X\n", a1, b1);
  }
  
  // ===== PREDICTIONS =====
  printf("\n===================== PREDICTIONS USING REGRESSION ======================\n");
  printf("%-10s %-15s %-25s %-25s\n", "Index", "X Value", "Original Prediction", "Transformed Prediction");
  printf("%-10s %-15s %-25s %-25s\n", "-----", "-------", "---", "---");
  for (int i = 0; i < n; i++) {
    double pred_orig = beta0_orig + beta1_orig * x[i];
    double pred_trans = beta0_trans + beta1_trans * x[i];
    printf("%-10d %-15.3lf %-25.3lf %-25.3lf\n", i+1, x[i], pred_orig, pred_trans);
  }
  
  // ===== RESIDUALS =====
  printf("\n============================== RESIDUALS ================================\n");
  printf("%-10s %-15s %-25s %-25s\n", "Index", "Actual Y", "Original Residual", "Transformed Residual");
  printf("%-10s %-15s %-25s %-25s\n", "-----", "--------", "---", "---");
  for (int i = 0; i < n; i++) {
    double pred_orig = beta0_orig + beta1_orig * x[i];
    double pred_trans = beta0_trans + beta1_trans * x[i];
    double residual_orig = y[i] - pred_orig;
    double residual_trans = y[i] - pred_trans;
    printf("%-10d %-15.3lf %-25.3lf %-25.3lf\n", i+1, y[i], residual_orig, residual_trans);
  }
  
  printf("\n=================================================================================\n");
  
  return 0;
}