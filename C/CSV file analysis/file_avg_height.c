// find average height, cgpa of all male students
// find average height, cgpa of all female students

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  
  int count = 0;
  
  
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
  
  int male_count = 0, female_count = 0;
  double male_sum = 0, female_sum = 0, male_avg, female_avg;
  double male_cg = 0, female_cg = 0, male_cg_avg, female_cg_avg;
  
  for(int i = 0; i < count; i++) {
    if(strcmp(gender[i], "Male") == 0) {
      male_sum += height[i];
      male_cg += cgpa[i];
      male_count++;
    }
    else if(strcmp(gender[i], "Female") == 0) {
      female_sum += height[i];
      female_cg += cgpa[i];
      female_count++;
    }
    else {
      printf("error\n");
    }
  }
  
  male_avg = male_sum / male_count;
  female_avg = female_sum / female_count;
  male_cg_avg = male_cg / male_count;
  female_cg_avg = female_cg / female_count;
  
  printf("\naverage height of male students = %.4lf\n", male_avg);
  printf("average height of female students = %.4lf\n", female_avg);
  
  printf("\naverage cgpa of male students = %.4lf\n", male_cg_avg);
  printf("average cgpa of female students = %.4lf\n", female_cg_avg);
  
  return 0;
}  