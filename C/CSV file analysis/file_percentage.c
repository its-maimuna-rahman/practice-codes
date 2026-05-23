// Main motive is to use nested "if" under for-loop in file analyzing C-program.


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
  
  int male_count = 0, female_count = 0, male_dhaka = 0, female_dhaka = 0;
  
  for(int i = 0; i < count; i++) {
    if(strcmp(gender[i], "Male") == 0) {
      male_count++;
      if(strcmp(division[i], "Dhaka") == 0) {
        male_dhaka++;
      }
    }
    else if(strcmp(gender[i], "Female") == 0) {
      female_count++;
      if(strcmp(division[i], "Dhaka") == 0) {
        female_dhaka++;
      }
    }
  }
  
  if (male_count > 0) {
    double percent_m = ((double)male_dhaka / male_count) * 100.0;
    printf("\nPercentage of males from Dhaka: %.2f%%\n", percent_m);
  }
  else {
    printf("No male entries found.\n");
  }
  
  
  if (female_count > 0) {
    double percent_f = ((double)female_dhaka / female_count) * 100.0;
    printf("Percentage of females from Dhaka: %.2f%%\n", percent_f);
  }
  else {
    printf("No female entries found in the dataset.\n");
  }
  
  return 0; 
}  