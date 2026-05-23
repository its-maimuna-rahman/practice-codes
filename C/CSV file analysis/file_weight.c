// 1. Highest and lowest weight and those students' gender and division

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
  
  int max_weight_index = 0;
  int min_weight_index = 0;
  
  for(int i = 1; i < count; i++) {
    if(weight[i] > weight[max_weight_index]) {
      max_weight_index = i;
    }
  }
  
  for(int i = 1; i < count; i++) {
    if(weight[i] < weight[min_weight_index]) {
      min_weight_index = i;
    }
  }
  
  printf("\nmaximum weight info :\n\n");
  printf("maximum weight = %.2lf\n", weight[max_weight_index]);
  printf("        gender = %s\n", gender[max_weight_index]);
  printf("        division = %s\n", division[max_weight_index]);
  
  printf("\nminimum weight info :\n\n");
  printf("minimum weight = %.2lf\n", weight[min_weight_index]);
  printf("        gender = %s\n", gender[min_weight_index]);
  printf("        division = %s\n", division[min_weight_index]);
  
  return 0;
}  