// multiplication table
#include <stdio.h>
int main(){
  int n,m,s=0;
  
  printf("n = ");
  scanf("%d", &n); // rows
  printf("m = ");
  scanf("%d", &m); // columns
  
  for(int i=1; i<=n; i++){ //row
    for(int j=1; j<=m; j++) { //column
      s=i*j;
      printf("%3.d ", s);
    }
    printf("\n");
  }
  return 0;
}