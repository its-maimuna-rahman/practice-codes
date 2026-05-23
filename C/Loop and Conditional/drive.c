/* Develop a program that will input the miles driven and gallon (gasoline) 
 * used for each tankful. The program should calculate and display the miles per
 * gallon obtained for each tankful. After processing all input information, 
 * the program should calculate and print the combined miles per gallon 
 * obtained for all tankfuls.
 */

#include <stdio.h>

int main(void) {
  float driven, gasoline, mpg;
  float driven_sum = 0, gasoline_sum = 0;
  
  printf("\n(-1) to gasoline to end the program\n");
  printf("\nGasoline used for each tankful = ");
  scanf("%f", &gasoline);
  
  while(gasoline != -1) {
    {
      printf("Miles driven = ");
      scanf("%f", &driven);
      
      mpg = driven / gasoline;
      printf("The miles/gallon for this tank was = %.2f", mpg);
      
      driven_sum += driven;
      gasoline_sum += gasoline;
      
      printf("\n\nGasoline used for each tankful = ");
      scanf("%f", &gasoline);
      
    } 
  }
  if(gasoline_sum != 0) { 
    printf("\nThe overall average miles/gallon was = %f\n", driven_sum / gasoline_sum);
  }
  
  return 0;
}