/*Write a program that reads temperature, humidity, and wind speed,
 and uses nested if statements to determine the weather condition.
 
 Rules:
 
 If temp > 35
    If humidity > 70 → “Hot and Humid”
    Else → “Hot and Dry”
 Else if temp between 20–35
    If wind > 30 → “Pleasant but Windy
    Else → “Pleasant”
 Else if temp < 20
    If humidity > 80 → “Cold and Foggy”
    Else → “Cold and Clear”
*/

#include <stdio.h>
int main() {
  int temp, humid, wind;
  
  printf("enter temperature = ");
  scanf("%d", &temp);
  printf("enter humidity = ");
  scanf("%d", &humid);
  printf("enter wind speed = ");
  scanf("%d", &wind);
  
  if(temp>35) {
    if(humid>70) {
      printf("hot and humid");
    }
    else {
      printf("hot and dry");
    }
  }
  else if(temp>=20 && temp<=35) {
    if(wind>30) {
      printf("Pleasant but Windy");
    }
    else {
      printf("plesant");
    }
  }
  else if(temp<20) {
    if(humid>80) {
      printf("cold and foggy");
    }
    else {
      printf("cold and clear");
    }
  }
  else {
    printf("invalid input for variables");
  }
  
  return 0;
  
}