// average, standard deviation of cgpa
// min and max cgpa details
// male, female separate average cgpa

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
  char gender[MAX_ENTRIES][20], division[MAX_ENTRIES][20];
  
  int count = 0, high_cg = 0;
  double cg_sum = 0, cg_avg, sum_sq = 0, sd;
  
  fgets(line, sizeof(line), file);
  
  while(fgets(line, sizeof(line), file)) {
    if(sscanf(line, "%lf,%lf,%10[^,],%10[^,],%lf",
              &height[count], &weight[count],
              gender[count], division[count],
              &cgpa[count]) == 5) {
      count++;
    }
  }
  
  fclose(file);
  
  for(int i = 0; i < count; i++) {        // average cg
    cg_sum += cgpa[i];
    if(cgpa[i] >= 3.50) {
      high_cg++;
    }
  }
  cg_avg = cg_sum / count;
  
  for(int i = 0; i < count; i++) {
    sum_sq += ((cgpa[i] - cg_avg) * (cgpa[i] - cg_avg));
  }
  
  sd = sqrt(sum_sq / count);        // population standard deviation
  
  int max_cg_index = 0, min_cg_index = 0;
  
  for(int i = 1; i < count; i++) {        // highest cg
    if(cgpa[i] > cgpa[max_cg_index]) {
      max_cg_index = i;
    }
  }
  
  for(int j = 1; j < count; j++) {        // lowest cg
    if(cgpa[j] < cgpa[min_cg_index]) {
      min_cg_index = j;
    }
  }
  
  double male_sum = 0, female_sum = 0, male_cg_avg, female_cg_avg;
  int male_count = 0, female_count = 0;
  
  for(int k = 0; k < count; k++) {
    if(strcmp(gender[k], "Male") == 0) {    // male cg average
      male_sum += cgpa[k];
      male_count++;
    }
    else if(strcmp(gender[k], "Female") == 0) {   // female cg average
      female_sum += cgpa[k];
      female_count++;
    }
    else {
      printf("error\n");
    }
  }
  
  male_cg_avg = male_sum / male_count;
  female_cg_avg = female_sum / female_count;
  
  double ol1, ol2;
  ol1 = cg_avg + (1.5 * sd);    // potential outliers
  ol2 = cg_avg - (1.5 * sd);
  
  printf("\ncgpa analysis :\n");
  printf("\naverage cgpa = %.3lf\n", cg_avg);
  printf("standard deviation (poplation) = %.3lf\n", sd);
  printf("students with cgpa equal and above 3.50 = %d\n", high_cg);
  
  printf("\nHIGHEST cgpa = %.2lf\n", cgpa[max_cg_index]);
  printf("        gender = %s\n", gender[max_cg_index]);
  printf("      division = %s\n", division[max_cg_index]);
  
  printf("\nLOWEST cgpa = %.2lf\n", cgpa[min_cg_index]);
  printf("        gender = %s\n", gender[min_cg_index]);
  printf("      division = %s\n", division[min_cg_index]);
  
  printf("\ntotal male = %d\n", male_count);
  printf("male cgpa average = %.3lf\n", male_cg_avg);
  
  printf("\ntotal female = %d\n", female_count);
  printf("female cgpa average = %.3lf\n", female_cg_avg);
  
  printf("\noutliers :\n");
  
  for(int i = 0; i < count; i++) {
    if(cgpa[i] > ol1 || cgpa[i] < ol2) {
      printf("%.2lf   ", cgpa[i]);
    }
  }
  
  return 0;
}