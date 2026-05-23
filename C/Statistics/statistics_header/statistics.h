#ifndef STATISTICS_H
#define STATISTICS_H

// SORT AND SEARCH
void sort(double arr[], int n);
void sort_str(char str[][100], int n);
int binary_search(double arr[], int n, double key);
int binary_search_str(char arr[][100], int n, char key[]);

// MAIN STATISTICS FUNCTIONS

// UNIVARIATE STATISTICS FUNCTIONS
double sum(double arr[], int n);
double average(double arr[], int n);
double median(double arr[], int n);
double mode(double arr[], int n);
double geometric_mean(double arr[], int n);
double harmonic_mean(double arr[], int n);
double weighted_mean(double x[], double w[], int n);
double min(double arr[], int n);
double max(double arr[], int n);
double mean_deviation(double arr[], int n);
double variance(double arr[], int n);
double standard_deviation(double arr[], int n);
double coefficient_of_variation(double arr[], int n);
double quartile(double arr[], int n, int q_num);
double iqr(double arr[], int n);
double quartile_deviation(double arr[], int n);
double raw_moment(double arr[], int n, int r);
double central_moment(double arr[], int n, int r);
double pearson_sk1(double arr[], int n);
double pearson_sk2(double arr[], int n);
double gamma1(double arr[], int n);
double beta1(double arr[], int n);
double beta2(double arr[], int n);
double gamma2(double arr[], int n);

// BIVARIATE STATISTICS FUNCTIONS
double covariance(double x[], double y[], int n);
double r(double x[], double y[], int n);
double regression_beta1(double x[], double y[], int n);
double regression_beta0(double x[], double y[], int n);
double R_square(double x[], double y[], int n);

//ORIGIN AND SCALE CHANGE FUNCTIONS (UNIVARIATE)
double mean_change(double arr[], int n, double a, double b);
double median_change(double arr[], int n, double a, double b);
double mode_change(double arr[], int n, double a, double b);
double geometric_mean_change(double arr[], int n, double a, double b);
double harmonic_mean_change(double arr[], int n, double a, double b);
double weighted_mean_change(double arr[], double weights[], int n, double a, double b);
double minimum_change(double arr[], int n, double a, double b);
double maximum_change(double arr[], int n, double a, double b);
double quartile_change(double arr[], int n, int q, double a, double b);
double variance_change(double arr[], int n, double a, double b);
double standard_deviation_change(double arr[], int n, double a, double b);
double mean_deviation_change(double arr[], int n, double a, double b);
double iqr_change(double arr[], int n, double a, double b);
double quartile_deviation_change(double arr[], int n, double a, double b);
double coefficient_of_variation_change(double arr[], int n, double a, double b);
double raw_moment_change(double arr[], int n, int r, double a, double b);
double central_moment_change(double arr[], int n, int r, double a, double b);

//ORIGIN AND SCALE CHANGE FUNCTIONS (BIVARIATE)
double covariance_change(double x[], double y[], int n, double a1, double b1, double a2, double b2);
double regression_beta1_change(double x[], double y[], int n, double a1, double b1, double a2, double b2);
double regression_beta0_change(double x[], double y[], int n, double a1, double b1, double a2, double b2);

#endif

