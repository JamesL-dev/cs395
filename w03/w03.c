/**************************************
 * Id: lass2922
 *
 * This is a 2^n brute force algorithmn!
 ***************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int calcSum(int n);

// Main Function
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   int sum = calcSum(n);
   printf("%d\n", sum);
}

// Function calculates 2^n
int calcSum(int n)
{
   int sum = 0;
   int base = 2;
   int power = n;
   int i;

   for (i = 0; i < n; i++)
   {
      sum = pow(base,power-1) + pow(2,power-1);
   }
   return sum;
}
