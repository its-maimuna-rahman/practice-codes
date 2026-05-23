// mean, variance and correlation coefficinet of height and weight

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 111

int main(void) {
  FILE *file = fopen("class_data.csv", "r");
  if(!file) {
    perror("file not found\n");
    return EXIT_FAILURE;
  }
  
  char line[MAX_LINE_LENGTH];
  double height[MAX_ENTRIES], weight[MAX_ENTRIES], cgpa[MAX_ENTRIES];
  
  int count = 0;
  
  fgets(line, sizeof(line), file);
  
  while(fgets(line, sizeof(line), file)) {
    if(sscanf(line, "%lf,%lf",
              &height[count], &weight[count]) == 2) {
      count++;
    }
  }
  
  double h_sum = 0, w_sum = 0, h_mean, w_mean, h_s = 0, w_s = 0, hw_s = 0,
         h_var, w_var, corr_coeff, coeff_det, alpha, beta;  
  
  for(int i = 0; i < count; i++) {
    h_sum += height[i];
    w_sum += weight[i];
  }
  
  h_mean = h_sum / count;
  w_mean = w_sum / count;
  
  for(int i = 0; i < count; i++) {
    h_s += (height[i] - h_mean) * (height[i] - h_mean);
    w_s += (weight[i] - w_mean) * (weight[i] - w_mean);
    hw_s += (height[i] - h_mean) * (weight[i] - w_mean);
  }
  
  h_var = h_s / count;    //population variance
  w_var = w_s / count;
  corr_coeff = hw_s / sqrt(h_s * w_s);
  coeff_det = corr_coeff * corr_coeff;
  
  //linear regression, weight = alpha + (beta * height) [y = weight, x = height]
  beta = hw_s / h_s;                   // beta = cov(x,y) / var(x) 
  alpha = w_mean - (beta * h_mean);    // alpha = mean(y) - [beta * mean(x)]
  
  fclose(file);
  
  printf("\nMEAN of HEIGHT = %.3lf\n", h_mean);
  printf("MEAN of WEIGHT = %.3lf\n", w_mean);
  printf("\nVARIANCE of HEIGHT = %.3lf\n", h_var);
  printf("VARIANCE of WEIGHT = %.3lf\n", w_var);
  printf("\nCORRELATION COEFFICIENT of height & weight = %.3lf\n", corr_coeff);
  printf("Coefficient of Determination = %.3lf\n", coeff_det);
  printf("\nlinear regression model : weight = %.4lf + (%.4lf * height)\n", alpha, beta);
  
  return 0; 
}  
  