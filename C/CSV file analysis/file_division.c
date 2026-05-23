// division wise other variables' average

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
  
  int dha_count = 0, raj_count = 0, khu_count = 0, chi_count = 0;
  
  double dha_h = 0, khu_h = 0, raj_h = 0, chi_h = 0;
  double dha_w = 0, khu_w = 0, raj_w = 0, chi_w = 0;
  double dha_c = 0, khu_c = 0, raj_c = 0, chi_c = 0;
  
  double dha_hav, dha_wav, dha_cav, raj_hav, raj_wav, raj_cav;
  double khu_hav, khu_wav, khu_cav, chi_hav, chi_wav, chi_cav;
  
  for(int i = 0; i < count; i++) {
    if(strcmp(division[i], "Dhaka") == 0) {
      dha_count++;
      dha_h += height[i];
      dha_w += weight[i];
      dha_c += cgpa[i];
    }
    else if(strcmp(division[i], "Rajshahi") == 0) {
      raj_count++;
      raj_h += height[i];
      raj_w += weight[i];
      raj_c += cgpa[i];
    }
    else if(strcmp(division[i], "Khulna") == 0) {
      khu_count++;
      khu_h += height[i];
      khu_w += weight[i];
      khu_c += cgpa[i];
    }
    else if(strcmp(division[i], "Chittagong") == 0) {
      chi_count++;
      chi_h += height[i];
      chi_w += weight[i];
      chi_c += cgpa[i];
    }
    else {
      printf("error\n");
    }
  }
  
  dha_hav = dha_h / dha_count;
  dha_wav = dha_w / dha_count;  
  dha_cav = dha_c / dha_count;
  
  raj_hav = raj_h / raj_count;
  raj_wav = raj_w / raj_count;  
  raj_cav = raj_c / raj_count;
  
  khu_hav = khu_h / khu_count;
  khu_wav = khu_w / khu_count;  
  khu_cav = khu_c / khu_count;
  
  chi_hav = chi_h / chi_count;
  chi_wav = chi_w / chi_count;  
  chi_cav = chi_c / chi_count;
  
  printf("\nDivision wise data analysis\n");
  
  printf("----------------------------------------------------------\n");
  printf("    division      avg height    avg weight    avg cgpa    \n");
  printf("----------------------------------------------------------\n");
  printf("    Dhaka         %.3lf         %.3lf         %.3lf       \n", dha_hav, dha_wav, dha_cav);
  printf("    Rajshahi      %.3lf         %.3lf         %.3lf       \n", raj_hav, raj_wav, raj_cav);
  printf("    Khulna        %.3lf         %.3lf         %.3lf       \n", khu_hav, khu_wav, khu_cav);
  printf("    Chittagong    %.3lf         %.3lf         %.3lf       \n", chi_hav, chi_wav, chi_cav);
  
 return 0; 
}