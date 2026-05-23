//cgpa frequency distribution and outlier

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
  
  int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
  
  for(int i = 0; i < count; i++) {
    if(cgpa[i] >= 2.00 && cgpa[i] < 2.50) {
      c1++;
    }
    else if(cgpa[i] >= 2.50 && cgpa[i] < 3.00) {
      c2++;
    }
    else if(cgpa[i] >= 3.00 && cgpa[i] < 3.50) {
      c3++;
    }
    else if(cgpa[i] >= 3.50) {
      c4++;
    }
    else {
      printf("error\n");
    }
  }
  
  printf("\nfrequency distribution by cgpa\n");
  printf("--------------------------------------------\n");
  printf("    range                   frequency       \n");
  printf("--------------------------------------------\n");
  printf("    2.00 - 2.49             %.2d       \n", c1);
  printf("    2.50 - 2.99             %.2d       \n", c2);
  printf("    3.00 - 3.49             %.2d       \n", c3);
  printf("    3.50 - 4.00             %.2d       \n", c4);
  
 return 0; 
}  
  