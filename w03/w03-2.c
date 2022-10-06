/**************************************
 * Id: lass2922
 *
 * This is a 2^n brute force algorithmn!
 ***************************************/

#include <stdlib.h>
#include <stdio.h>

int power(int x, int n);

// Main Function
int main(int argc, char *argv[])
{
   int base = 2;
   int n = atoi(argv[1]);
   int sum = power(base, n);
   printf("%d\n", sum);

   return 0;
}

// Function calculates 2^n
int power(int x, int n)
{
   if (n == 0)
   {
      return 1;
   }
   return power(x, n-1) + power(x, n-1);
}
