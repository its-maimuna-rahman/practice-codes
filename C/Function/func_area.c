#include <stdio.h>
#include <math.h>

void triangle(double *l, double *w, double *area, double *per) {
  *area = *l * *w;
  *per = 2 * (*l + *w);
  
}



int main(void) {
  double l, w, area, per;
  
  printf("length = ");
  scanf("%lf", &l);
  printf("width = ");
  scanf("%lf", &w);
  
  triangle(&l, &w, &area, &per);
  
  printf("area = %.3lf\n", area);
  printf("perimeter = %.3lf\n", per);
  
  return 0;
}