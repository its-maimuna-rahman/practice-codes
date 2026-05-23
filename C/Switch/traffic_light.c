/*
 Description:
 Input a color code (R, Y, G) for Red, Yellow, or Green,
 and a mode (1 = normal, 2 = night).
 Use nested switch:
 If mode = 1:
 R → “Stop” , Y → “Ready” , G → “Go”
 If mode = 2:
 R → “Blinking Red – proceed with caution”
 Y → “Off”
 G → “Blinking Green – pedestrian mode”
 */

#include <stdio.h>
int main() {
  char color, mode;
  
  printf("enter mode = ");
  scanf(" %c", &mode);
  printf("enter color = ");
  scanf(" %c", &color);
  
  switch(mode) {
        case '1' :
            switch(color) {
                case 'R' :
                    printf("stop");
                    break;
                case 'Y' :
                    printf("ready");
                    break;
                case 'G' :
                    printf("go");
                    break;
                default :
                    printf("invalid input for color");
                    break;
            }
            break;
        case '2' :
            switch(color) {
                case 'R' :
                    printf("Blinking Red – proceed with caution");
                    break;
                case 'Y' :
                    printf("off");
                    break;
                case 'G' :
                    printf("Blinking Green – pedestrian mode");
                    break;
                default :
                    printf("invalid input for color");
                    break;
            }
            break;
        default :
            printf("invalid input for mode");
            break;
  }
  
  return 0;
}