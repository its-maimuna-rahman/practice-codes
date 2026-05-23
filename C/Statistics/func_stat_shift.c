#include <stdio.h>
#include <math.h>

double average(double arr[], int n);
double variance(double arr[], int n);
double standard_deviation(double arr[], int n);
double raw_moment(double arr[], int n, int r);
double central_moment(double arr[], int n, int r);

// Helper function implementations
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

// ===== ORIGIN AND SCALE CHANGE FUNCTIONS =====
// Transformation: y = a + bx (a = origin, b = scale)

// Mean transformation: E(Y) = a + b*E(X)
double mean_change(double arr[], int n, double a, double b) {
  double mx, my;
  mx = average(arr, n);
  my = a + (b * mx);
  return my;
}

// Variance transformation: Var(Y) = b²*Var(X)
// (origin change doesn't affect variance)
double variance_change(double arr[], int n, double a, double b) {
  double vx, vy;
  vx = variance(arr, n);
  vy = b * b * vx;
  return vy;
}

// Standard deviation transformation: SD(Y) = |b|*SD(X)
double standard_deviation_change(double arr[], int n, double a, double b) {
  double sdx, sdy;
  sdx = standard_deviation(arr, n);
  sdy = fabs(b) * sdx;
  return sdy;
}

// Raw moment transformation: E(Y^r) = (a + b*X)^r
// This requires binomial expansion
double raw_moment_change(double arr[], int n, int r, double a, double b) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pow(a + b * arr[i], r);
  }
  return sum / n;
}

// Central moment transformation: E((Y - E(Y))^r) = b^r * E((X - E(X))^r)
double central_moment_change(double arr[], int n, int r, double a, double b) {
  double mtx, mty;
  mtx = central_moment(arr, n, r);
  mty = pow(b, r) * mtx;
  return mty;
}

int main(void) {
  int n, r;
  double a, b;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  double arr[n];
  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }
  
  printf("\nEnter origin change (a): ");
  scanf("%lf", &a);
  printf("Enter scale change (b): ");
  scanf("%lf", &b);
  printf("Enter moment order (r) for raw and central moments: ");
  scanf("%d", &r);
  
  // Calculate transformed statistics
  double my, vy, sdy, rmy, cmy;
  
  my = mean_change(arr, n, a, b);
  vy = variance_change(arr, n, a, b);
  sdy = standard_deviation_change(arr, n, a, b);
  rmy = raw_moment_change(arr, n, r, a, b);
  cmy = central_moment_change(arr, n, r, a, b);
  
  // Display results
  printf("\n=============== RESULTS ===============\n");
  printf("\nTransformation: Y = %.2lf + %.2lf*X\n\n", a, b);
  printf("Changed mean                  = %.3lf\n", my);
  printf("Changed variance              = %.3lf\n", vy);
  printf("Changed std deviation         = %.3lf\n", sdy);
  printf("Changed raw moment (r=%d)     = %.3lf\n", r, rmy);
  printf("Changed central moment (r=%d) = %.3lf\n", r, cmy);
  printf("=======================================\n");
  
  return 0;
}