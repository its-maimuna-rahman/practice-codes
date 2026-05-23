/* C prog by reading a csv file
 * 1. define row num, max char in a line
 * 2. input file
 * 3. check if file exists or not
 * 4. define file's and other variables datatype
 * 5. read first line and ignore
 * 6. read the full file
 * 7. close the file
 * 8. do further work */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 111

int main() {
  
  FILE *file = fopen("class_data.csv", "r");
  if(!file) {
    perror("file not found\n");
    return EXIT_FAILURE;
  }
  
  char line[MAX_LINE_LENGTH];
  double height[MAX_ENTRIES], weight[MAX_ENTRIES], cgpa[MAX_ENTRIES];
  char gender[MAX_ENTRIES][20], division[MAX_ENTRIES][20];
  
  int count = 0, male_count = 0, female_count = 0, other_count = 0;
  int dha = 0, raj = 0, khu = 0, chi = 0, oth = 0;
  
  fgets(line, sizeof(line), file);
  
  while(fgets(line, sizeof(line), file)) {
    if(sscanf(line, "%lf,%lf,%10[^,],%10[^,],%lf", &height[count],
              &weight[count], gender[count],                              
              division[count], &cgpa[count]) == 5) {
      count++;
    }
  }
  
  fclose(file);
  
  for(int i = 0; i < count; i++) {
    if(strcmp(gender[i], "Male") == 0) {
      male_count++;
    }
    else if(strcmp(gender[i], "Female") == 0) {
      female_count++;
    }
    else {
      other_count++;
    }
  }
  
  for(int i = 0; i < count; i++) {
    if(strcmp(division[i], "Dhaka") == 0) {
      dha++;
    }
    else if(strcmp(division[i], "Rajshahi") == 0) {
      raj++;
    }
    else if(strcmp(division[i], "Khulna") == 0) {
      khu++;
    }
    else if(strcmp(division[i], "Chittagong") == 0) {
      chi++;
    }
    else {
      oth++;
    }
  }
  
  
  
  printf("\ngender frequency distribution :\n");
  printf("\nmale = %d\n", male_count);
  printf("female = %d\n", female_count);
  printf("other = %d\n", other_count);
  
  printf("\ndivision frequency distribution :\n");
  printf("\nDhaka = %d\n", dha);
  printf("Rajshahi = %d\n", raj);
  printf("Khulna = %d\n", khu);
  printf("Chittagong = %d\n", chi);
  printf("other = %d\n", oth);
  
  return 0;
}