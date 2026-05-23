// top 10 cgpa students' details

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
  
  for(int i = 0; i < count - 1; i++) {          // descending order by cgpa
    for(int j = 0; j < count - i - 1; j++) {
      if(cgpa[j] < cgpa[j + 1]) {
        double temp_c = cgpa[j];
        cgpa[j] = cgpa[j + 1];
        cgpa[j + 1] = temp_c;
        
        double temp_h = height[j];
        height[j] = height[j + 1];
        height[j + 1] = temp_h;
        
        double temp_w = weight[j];
        weight[j] = weight[j + 1];
        weight[j + 1] = temp_w;
        
        char temp_g[10];
        strcpy(temp_g, gender[j]);
        strcpy(gender[j], gender[j + 1]);
        strcpy(gender[j + 1], temp_g);
        
        char temp_div[10];
        strcpy(temp_div, division[j]);
        strcpy(division[j], division[j + 1]);
        strcpy(division[j + 1], temp_div);
      }
    }
  }
  
  printf("\ntop 10 cgpa :\n");
  printf("-------------------------------------------------\n");
  printf("  merit  cgpa  height  weight  gender  division  \n");
  printf("-------------------------------------------------\n");
  printf("    1   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[0], height[0], weight[0], gender[0], division[0]);
  printf("    2   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[1], height[1], weight[1], gender[1], division[1]);
  printf("    3   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[2], height[2], weight[2], gender[2], division[2]);
  printf("    4   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[3], height[3], weight[3], gender[3], division[3]);
  printf("    5   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[4], height[4], weight[4], gender[4], division[4]);
  printf("    6   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[5], height[5], weight[5], gender[5], division[5]);
  printf("    7   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[6], height[6], weight[6], gender[6], division[6]);
  printf("    8   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[7], height[7], weight[7], gender[7], division[7]);
  printf("    9   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[8], height[8], weight[8], gender[8], division[8]);
  printf("   10   %.2lf   %.2lf   %.2lf   %s      %s  \n", cgpa[9], height[9], weight[9], gender[9], division[9]);
  
  return 0;
  
}  