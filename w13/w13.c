/*********************************************************
 * Id: lass2922
 *
 * Russian peasant multiplaction program
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>

// Main Function
int main(int argc, char *argv[])
{
   int num1 = atoi(argv[1]);
   int num2 = atoi(argv[2]);

   int runningTotal = 0;

   while (num1 != 1)
   {
      printf("%6d %6d",  num1, num2);
      if (num1 % 2 == 1)
      {
         runningTotal += num2;
         printf(" %6d\n", num2);
      }
      else
      {
         printf("\n");
      }
      num1 /= 2;
      num2 *= 2;
   }
   printf("%6d %6d %6d\n", num1, num2, num2);
   printf("%20s\n", "------");
   printf("%20d\n", runningTotal+num2);
   return 0;
}

