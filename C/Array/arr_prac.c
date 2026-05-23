#include <stdio.h>
int main () {
  
  int nums[] = {10, 20, 30, 40, 50};
  char alp[] = {'A', 'B', 'C', 'D', 'E'};
  char name[] = "formula one";
  
  int num_of_ele_alp = sizeof(alp)/sizeof(alp[0]);
  printf("alp size = %d\n", num_of_ele_alp);
  
  int num_of_ele_nums = sizeof(nums)/sizeof(nums[0]);
  printf("num size = %d\n", num_of_ele_nums);
  
  printf("\n\n");
  
  for(int i=0; i<5; i++) {
    printf("%d ", nums[i]);
  }
  
  printf("\n\n");
  
  for(int j=0; j<5; j++) {
    printf("%c ", alp[j]);
  }
  
  printf("\n\n");
  
  for(int k=0; k<11; k++) {
    printf("%c", name[k]);
  }
  
  return 0;
  
}