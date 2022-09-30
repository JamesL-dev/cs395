/*********************************************
 * Id: lass2922
 * 
 * Min Distance Algorithm
 *********************************************/


#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int minDistance(int array[], int n);

// Main function
int main(int argc, char *argv[])
{
   int array[argc];
   int i;
   for (i = 1; i < argc; i++)
   {
      array[i-1] = atoi(argv[i]);
   }   
   int minDist = minDistance(array, argc);
   printf("The minimum distance is %d\n", minDist);

   return 0;
}

// Min distance function
int minDistance(int array[], int n)
{
   int i, j;
   int dmin = INT_MAX;

   for (i = 0; i < (n-1); i++)
   {
      for (j = 0; j < (n-1); j++)
      {
         if (i != j && abs(array[i] - array[j]) < dmin)
         {
            dmin = abs(array[i] - array[j]);
            printf("min is currently %d\n", dmin);
         }
      }
   }
   return dmin;
}

