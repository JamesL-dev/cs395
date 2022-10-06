/******************************************************************
 * Id: lass2922
 *
 * This program is a better version of the min distance algorithm
 ******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int minDistance(int array[], int n);
void swap(int* xp, int* yp);
void selectionSort(int array[], int n);

// Main function
int main(int argc, char *argv[])
{
   int array[argc];
   int i;
   for (i = 1; i < argc; i++)
   {
      array[i-1] = atoi(argv[i]);
   }
   int n = sizeof(array) / sizeof(array[0]);

   selectionSort(array, n);

   int minDist = minDistance(array, argc);
   printf("The minimum distance is %d\n", minDist);

   return 0;
}

// Min distance function
int minDistance(int array[], int n)
{
   int i, j, temp;
   int dmin = INT_MAX;
   for (i = 0; i < (n-2); i++)
   {
      for (j = i + 1; j < (n-1); j++)
      {
         temp = abs(array[i] - array[j]);
         if (temp < dmin)
         {
            dmin = temp;
         }
      }
   }
   return dmin;
}

// Swap function for selection sort
void swap(int* xp, int* yp)
{
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

// Selection sort function to presort array
void selectionSort(int arr[], int n)
{
   int i, j, min_idx;

   for (i = 0; i < n - 1; i++)
   {
      min_idx = i;
      for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
      min_idx = j;

      swap(&arr[min_idx], &arr[i]);
   }
}
