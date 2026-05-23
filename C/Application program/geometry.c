/*
 area+perimeter/volume calculator
 input dimention, shape
 first switch - shape - 2d or 3d
 nested 2nd switch - if 2d - circle - input - radius
 rectangle - input length, width
 triangle - input height, base
 compute - area, perimeter and print
 if 3d - sphere - input - radius
 cube - input - length, width, height
 cylinder - input - radius, height
 compute - volume and print
 
 */

#include <stdio.h>
#include <math.h>
int main() {
  int dim, sp1, r1, area1, per1, l1, w1, area2, per2,
      a, b, c, s, area3, per3,
      sp2, r2, vol1, x, y, z, vol2, r3, h, vol3;
  
  printf("enter dimention (1 for 2D & 2 for 3D) = ");
  scanf("%d", &dim);
  
  switch(dim) {
              case 1: 
                      printf("1. circle\n2. rectangle\n3. triangle\n");
                      printf("enter shape (1,2 or 3) = ");
                      scanf("%d", &sp1);
    
                  switch(sp1) {
                            case 1:
                                    printf("circle radius = ");
                                    scanf("%d", &r1);
                                    area1=3.14*r1*r1;
                                    per1=2*3.14*r1;
                                    printf("area= %d\n", area1);
                                    printf("perimeter= %d\n", per1);
                                    break;
                                    
                             case 2:
                                printf(" rectangle length = ");
                                scanf("%d", &l1);
                                printf("width = ");
                                scanf("%d", &w1);
                                area2=l1*w1;
                                per2=2*(l1*w1);
                                printf("area= %d\n", area2);
                                printf("perimeter= %d\n", per2);
                                break;
                                
                             case 3:
                                printf("triangle a = ");
                                scanf("%d", &a);
                                printf("b = ");
                                scanf("%d", &b);
                                printf("c = ");
                                scanf("%d", &c);
                                s=(a+b+c)/2;
                                area3=sqrt(s*(s-a)*(s-b)*(s-c));
                                per3=a+b+c;
                                printf("area= %d\n", area3);
                                printf("perimeter= %d\n", per3);
                                break;
                                
                             default:
                               printf("invalid input for shape\n");
                               break;
                             }
                             break;
                  
              case 2: 
                      printf("1. sphere\n2. cuboid\n3. cylinder\n");
                      printf("enter shape (1,2 or 3) = ");
                      scanf("%d", &sp2);
    
                  switch(sp2) {
                            case 1:
                                printf("enter sphere radius = ");
                                scanf("%d", &r2);
                                vol1=(4/3)*3.14*r2*r2*r2;
                                printf("volume= %d\n", vol1);
                                break;
                                
                            case 2:
                                printf("enter cuboid x= ");
                                scanf("%d", &x);
                                printf("enter y= ");
                                scanf("%d", &y);
                                printf("enter z= ");
                                scanf("%d", &z);
                                vol2=x*y*z;
                                printf("volume= %d\n", vol2);
                                break;
                                
                            case 3:
                                printf("cylinder radius = ");
                                scanf("%d", &r3);
                                printf("height= ");
                                scanf("%d", &h);
                                vol3=3.14*r3*r3*h;
                                printf("volume= %d\n", vol3);
                                break;
                                
                            default:
                                printf("invalid input for shape\n");
                                break;
                            }
                            break;
              default:
                      printf("invalid input for dimention");
                      break;
  }
  
  
  return 0;
}