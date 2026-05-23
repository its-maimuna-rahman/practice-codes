#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistics.h"

void print_univariate_stats(double arr[], int n, const char *label);
void print_univariate_stats_all(double arr[], int n, const char *label);
void print_bivariate_stats(double x[], double y[], int n);

int main() {
  int data_type;
  int transform_needed;
  int print_type;
  int n;
  
  // Ask for data type
  printf("========================================\n");
  printf("      STATISTICS ANALYSIS PROGRAM       \n");
  printf("========================================\n\n");
  
  printf("What type of data do you have?\n");
  printf("1. Univariate (One variable)\n");
  printf("2. Bivariate (Two variables)\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &data_type);
  
  if (data_type == 1) {
    // UNIVARIATE DATA
    printf("\n--- UNIVARIATE DATA ANALYSIS ---\n\n");
    
    printf("Enter the number of observations: ");
    scanf("%d", &n);
    
    double *arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
      printf("Memory allocation failed!\n");
      return 1;
    }
    
    printf("Enter the data values:\n");
    for (int i = 0; i < n; i++) {
      printf("Value %d: ", i + 1);
      scanf("%lf", &arr[i]);
    }
    
    printf("\nDo you need to shift scale and origin?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &transform_needed);
    
    if (transform_needed == 1) {
      // WITH TRANSFORMATION
      double a, b;
      printf("\nEnter the transformation parameters:\n");
      printf("Transformed value = a + b * (original value)\n");
      printf("Enter a (origin shift): ");
      scanf("%lf", &a);
      printf("Enter b (scale factor): ");
      scanf("%lf", &b);
      
      printf("\n========================================\n");
      printf("       UNIVARIATE STATISTICS REPORT     \n");
      printf("========================================\n\n");
      
      print_univariate_stats_all(arr, n, "Original Data");
      
      printf("\n----------------------------------------\n");
      printf("TRANSFORMED DATA (Y = %.2lf + %.2lf * X)\n", a, b);
      printf("----------------------------------------\n\n");
      
      // Create transformed array
      double *arr_transformed = (double *)malloc(n * sizeof(double));
      for (int i = 0; i < n; i++) {
        arr_transformed[i] = a + b * arr[i];
      }
      
      print_univariate_stats_all(arr_transformed, n, "Transformed Data");
      
      free(arr_transformed);
    } else {
      // WITHOUT TRANSFORMATION
      printf("\n========================================\n");
      printf("       UNIVARIATE STATISTICS REPORT     \n");
      printf("========================================\n\n");
      
      print_univariate_stats_all(arr, n, "Data");
    }
    
    free(arr);
    
  } else if (data_type == 2) {
    // BIVARIATE DATA
    printf("\n--- BIVARIATE DATA ANALYSIS ---\n\n");
    
    printf("Enter the number of observations: ");
    scanf("%d", &n);
    
    double *x = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));
    
    if (x == NULL || y == NULL) {
      printf("Memory allocation failed!\n");
      return 1;
    }
    
    printf("Enter the data values (X, Y pairs):\n");
    for (int i = 0; i < n; i++) {
      printf("Pair %d:\n", i + 1);
      printf("  X value: ");
      scanf("%lf", &x[i]);
      printf("  Y value: ");
      scanf("%lf", &y[i]);
    }
    
    printf("\nDo you need to shift scale and origin?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &transform_needed);
    
    if (transform_needed == 1) {
      // WITH TRANSFORMATION
      double a1, b1, a2, b2;
      printf("\nEnter the transformation parameters:\n");
      printf("Transformed X = a1 + b1 * (original X)\n");
      printf("Transformed Y = a2 + b2 * (original Y)\n\n");
      printf("For X: Enter a1 (origin shift): ");
      scanf("%lf", &a1);
      printf("For X: Enter b1 (scale factor): ");
      scanf("%lf", &b1);
      printf("For Y: Enter a2 (origin shift): ");
      scanf("%lf", &a2);
      printf("For Y: Enter b2 (scale factor): ");
      scanf("%lf", &b2);
      
      printf("\nWhich statistics do you want to print?\n");
      printf("1. All univariate and bivariate statistics\n");
      printf("2. Only bivariate statistics (with univariate for reference)\n");
      printf("Enter your choice (1 or 2): ");
      scanf("%d", &print_type);
      
      printf("\n========================================\n");
      printf("       BIVARIATE STATISTICS REPORT      \n");
      printf("========================================\n\n");
      printf("ORIGINAL DATA\n");
      printf("----------------------------------------\n\n");
      
      if (print_type == 1) {
        // Print all univariate for both x and y
        print_univariate_stats_all(x, n, "X (Original)");
        printf("\n");
        print_univariate_stats_all(y, n, "Y (Original)");
      } else {
        // Print only summary univariate stats
        print_univariate_stats(x, n, "X (Original)");
        printf("\n");
        print_univariate_stats(y, n, "Y (Original)");
      }
      
      printf("\n");
      print_bivariate_stats(x, y, n);
      
      // Create transformed arrays
      double *x_transformed = (double *)malloc(n * sizeof(double));
      double *y_transformed = (double *)malloc(n * sizeof(double));
      
      for (int i = 0; i < n; i++) {
        x_transformed[i] = a1 + b1 * x[i];
        y_transformed[i] = a2 + b2 * y[i];
      }
      
      printf("\n----------------------------------------\n");
      printf("TRANSFORMED DATA\n");
      printf("X = %.2lf + %.2lf * (Original X)\n", a1, b1);
      printf("Y = %.2lf + %.2lf * (Original Y)\n", a2, b2);
      printf("----------------------------------------\n\n");
      
      if (print_type == 1) {
        // Print all univariate for both x and y
        print_univariate_stats_all(x_transformed, n, "X (Transformed)");
        printf("\n");
        print_univariate_stats_all(y_transformed, n, "Y (Transformed)");
      } else {
        // Print only summary univariate stats
        print_univariate_stats(x_transformed, n, "X (Transformed)");
        printf("\n");
        print_univariate_stats(y_transformed, n, "Y (Transformed)");
      }
      
      printf("\n");
      print_bivariate_stats(x_transformed, y_transformed, n);
      
      free(x_transformed);
      free(y_transformed);
      
    } else {
      // WITHOUT TRANSFORMATION
      printf("\nWhich statistics do you want to print?\n");
      printf("1. All univariate and bivariate statistics\n");
      printf("2. Only bivariate statistics (with univariate for reference)\n");
      printf("Enter your choice (1 or 2): ");
      scanf("%d", &print_type);
      
      printf("\n========================================\n");
      printf("       BIVARIATE STATISTICS REPORT      \n");
      printf("========================================\n\n");
      
      if (print_type == 1) {
        // Print all univariate for both x and y
        print_univariate_stats_all(x, n, "X");
        printf("\n");
        print_univariate_stats_all(y, n, "Y");
      } else {
        // Print only summary univariate stats
        print_univariate_stats(x, n, "X");
        printf("\n");
        print_univariate_stats(y, n, "Y");
      }
      
      printf("\n");
      print_bivariate_stats(x, y, n);
    }
    
    free(x);
    free(y);
    
  } else {
    printf("Invalid choice! Please enter 1 or 2.\n");
    return 1;
  }
  
  printf("\n========================================\n");
  printf("         ANALYSIS COMPLETE              \n");
  printf("========================================\n");
  
  return 0;
}

// Function to print all univariate statistics
void print_univariate_stats_all(double arr[], int n, const char *label) {
  printf("STATISTICS FOR %s:\n", label);
  printf("----------------------------------------\n");
  printf("Count:                           %d\n", n);
  printf("Sum:                             %.6lf\n", sum(arr, n));
  printf("Mean (Average):                  %.6lf\n", average(arr, n));
  printf("Median:                          %.6lf\n", median(arr, n));
  printf("Mode:                            %.6lf\n", mode(arr, n));
  printf("Geometric Mean:                  %.6lf\n", geometric_mean(arr, n));
  printf("Harmonic Mean:                   %.6lf\n", harmonic_mean(arr, n));
  printf("Minimum:                         %.6lf\n", min(arr, n));
  printf("Maximum:                         %.6lf\n", max(arr, n));
  printf("\nDISPERSION MEASURES:\n");
  printf("Range:                           %.6lf\n", max(arr, n) - min(arr, n));
  printf("Mean Deviation:                  %.6lf\n", mean_deviation(arr, n));
  printf("Variance:                        %.6lf\n", variance(arr, n));
  printf("Standard Deviation:              %.6lf\n", standard_deviation(arr, n));
  printf("Coefficient of Variation:        %.6lf\n", coefficient_of_variation(arr, n));
  printf("\nQUARTILE MEASURES:\n");
  printf("Q1 (25th Percentile):            %.6lf\n", quartile(arr, n, 1));
  printf("Q2 (50th Percentile/Median):    %.6lf\n", quartile(arr, n, 2));
  printf("Q3 (75th Percentile):            %.6lf\n", quartile(arr, n, 3));
  printf("Interquartile Range (IQR):       %.6lf\n", iqr(arr, n));
  printf("Quartile Deviation:              %.6lf\n", quartile_deviation(arr, n));
  printf("\nMOMENTS:\n");
  printf("Raw Moment (r=1):                %.6lf\n", raw_moment(arr, n, 1));
  printf("Raw Moment (r=2):                %.6lf\n", raw_moment(arr, n, 2));
  printf("Raw Moment (r=3):                %.6lf\n", raw_moment(arr, n, 3));
  printf("Raw Moment (r=4):                %.6lf\n", raw_moment(arr, n, 4));
  printf("Central Moment (r=1):            %.6lf\n", central_moment(arr, n, 1));
  printf("Central Moment (r=2):            %.6lf\n", central_moment(arr, n, 2));
  printf("Central Moment (r=3):            %.6lf\n", central_moment(arr, n, 3));
  printf("Central Moment (r=4):            %.6lf\n", central_moment(arr, n, 4));
  printf("\nSKEWNESS MEASURES:\n");
  printf("Pearson's Skewness (SK1):        %.6lf\n", pearson_sk1(arr, n));
  printf("Pearson's Skewness (SK2):        %.6lf\n", pearson_sk2(arr, n));
  printf("Gamma1 (Fisher's Skewness):      %.6lf\n", gamma1(arr, n));
  printf("\nKURTOSIS MEASURES:\n");
  printf("Beta1:                           %.6lf\n", beta1(arr, n));
  printf("Beta2:                           %.6lf\n", beta2(arr, n));
  printf("Gamma2 (Fisher's Kurtosis):      %.6lf\n", gamma2(arr, n));
  printf("\n");
}

// Function to print summary univariate statistics (for reference in bivariate)
void print_univariate_stats(double arr[], int n, const char *label) {
  printf("SUMMARY STATISTICS FOR %s:\n", label);
  printf("----------------------------------------\n");
  printf("Count:                           %d\n", n);
  printf("Mean:                            %.6lf\n", average(arr, n));
  printf("Median:                          %.6lf\n", median(arr, n));
  printf("Mode:                            %.6lf\n", mode(arr, n));
  printf("Standard Deviation:              %.6lf\n", standard_deviation(arr, n));
  printf("Variance:                        %.6lf\n", variance(arr, n));
  printf("Minimum:                         %.6lf\n", min(arr, n));
  printf("Maximum:                         %.6lf\n", max(arr, n));
  printf("Range:                           %.6lf\n", max(arr, n) - min(arr, n));
  printf("\n");
}

// Function to print bivariate statistics
void print_bivariate_stats(double x[], double y[], int n) {
  printf("BIVARIATE STATISTICS:\n");
  printf("----------------------------------------\n");
  printf("Covariance (X, Y):               %.6lf\n", covariance(x, y, n));
  printf("Correlation Coefficient (r):    %.6lf\n", r(x, y, n));
  printf("\nLINEAR REGRESSION (Y = beta0 + beta1*X):\n");
  printf("Slope (beta1):                      %.6lf\n", regression_beta1(x, y, n));
  printf("Intercept (beta0):                  %.6lf\n", regression_beta0(x, y, n));
  printf("R-squared (R^2):                    %.6lf\n", R_square(x, y, n));
  printf("\n");
}