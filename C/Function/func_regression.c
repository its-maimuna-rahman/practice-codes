#include <stdio.h>
#include <math.h>

double sum(double arr[], int n) {
  double s = 0;
  for(int i = 0; i < n; i++) {
    s += arr[i];
  }  
  return s;
}

double average(double arr[], int n) {
  double s = sum(arr, n);
  return s / n;
  
}


// --------------33. coefficient of correlation ----------------
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

// ---------------34. beta for regression --------------
double regression_beta(double x[], double y[], int n) {
  double sum_xy = 0, sum_x = 0;                 // beta = cov(x,y) / var(x)
  double mx = average(x, n);
  double my = average(y, n);
  
  for(int i = 0; i < n; i++) {
    sum_xy += (x[i] - mx) * (y[i] - my);
    sum_x += (x[i] - mx) *(x[i] - mx);
  }
  return sum_xy / sum_x;
}

// ---------------35. alpha for regression --------------
double regression_alpha(double x[], double y[], int n) {
  
  double mx = average(x, n);                  // alpha = mean(y) - beta*mean(x)
  double my = average(y, n);
  double beta = regression_beta(x, y, n);
  
  return (my - (beta * mx)); 
}

//-------------36. Coefficient of Determination ------------------
double R_square(double x[], double y[], int n) {
  double R = r(x, y, n);
  return (R * R);
}

int main(void) {
  int n;
  double a, b, r;
  
  printf("Enter number of observations: ");
  scanf("%d", &n);
  
  double x[n], y[n], w[n];
  
  // ---- Input X values ----
  printf("Enter %d values for X:\n", n);
  for(int i = 0; i < n; i++) {
    scanf("%lf", &x[i]);
    w[i] = i + 1;   // simple weights: 1,2,3,...,n
  }
  
  // ---- Input Y values ----
  printf("Enter %d values for Y:\n", n);
  for(int i = 0; i < n; i++) {
    scanf("%lf", &y[i]);
  }
  
  a = regression_alpha(x, y, n);
  b = regression_beta(x, y, n);
  r = R_square(x, y, n);
  
  printf("alpha = %.3lf\n", a);
  printf("beta = %.3lf\n", b);
  printf("R sq = %.3lf\n", r);
  
  return 0;
}  
  
  
