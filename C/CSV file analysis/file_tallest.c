//Find the tallest student print his/her max height, gender, division, cgpa.

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
  
  int tallest_index = 0;
  
  for(int i = 1; i < count; i++) {    //Start from i=1 bec tallest_index = 0.
    if(height[i] > height[tallest_index]) {    // max HEIGHT
      tallest_index = i;                       // max height's INDEX
    }
  }
  
  printf("\ntallest student's height = %.2lf\n", height[tallest_index]);
  printf("tallest student's gender = %s\n", gender[tallest_index]);
  printf("tallest student's division = %s\n", division[tallest_index]);
  printf("tallest student's cgpa = %.2lf\n", cgpa[tallest_index]);
  
  return 0;
}