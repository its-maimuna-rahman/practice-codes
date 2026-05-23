/* short algorithm : 10 student, 1 for pass, 2 for fail.
 * 1. take input 10 times individually by printing "Enter result", will accept
 *    '1' or '2' only (if statement).
 *    i am using "for" loop for this.
 * 2. if input 1 OR 2 : count '1' and '2' (i am using while loop),
 *    print the count of '1' and '2'.
 *    else invalid input.
 * 4. if res('1') > 8, then print "bonus to instructor"
 *    else "no bonus".
 
 */


#include <stdio.h>
int main() {
  int res;
  int s=0;
  int t=0;
  
  for(int i=1; i<=10; i++) {        //taking 10 input
    printf("Enter result = ");
    scanf("%d", &res);
    
    
    if(res==1 || res ==2) {       
      int j=1;
      int k=1;
      
      // s declared at first
      while(res==1 && j<=1) {
        s=s+1;
        j++;
      }
      // t declared at first
      while(res==2 && k<=1) {
        t=t+1;
        k++;
      }
    }
    else {
      printf("invalid input, enter 1 or 2\n");
    }
  }
  printf("passed = %d\n", s);
  printf("failed = %d\n", t);
  
  if(s>=8) {                        // bonus or not
    printf("bonus to instructor\n");  
  }
  else {
    printf("no bonus\n");
  }
  
  
  return 0;
}