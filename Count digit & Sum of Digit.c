#include <stdio.h>

int main() {
 int n;
 int sum=0;
  int count = 0;
   printf("Enter a Number : ");
   scanf("%d", &n);
    // For sum
    int x=n;
   while (x != 0) {
        sum = sum + x % 10;
        x = x / 10;
    }
  //For count digit 
   while (n!=0)
   {
      n /= 10;
     ++count;
   }
   
 
   
   printf("    Number of digits: %d    \n", count);
    printf("    Sum of digits :  %d    ",sum);
 }
