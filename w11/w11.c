/*******************************************************************
 * Id: lass2922
 *
 * This program uses insertion sort to organize an array given in the command line
 ********************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int n);
void printArray(int array[], int n, int split);

// Main function
int main(int argc, char *argv[])
{
   int n = argc - 1;
   int array[n];

   int i;
   for (i = 0; i < n; i++)
   {
      array[i] = atoi(argv[i+1]);
   }

   insertionSort(array, n);

   return 0;
}

// Insertion sort function
void insertionSort(int array[], int n)
{
   int i;
   for (i = 1; i < n; i++)
   {
      printArray(array, n, i);

      int currentValue = array[i];
      int j = i - 1;

      while (j >= 0 && array[j] > currentValue)
      {
         array[j + 1] = array[j];
         j--;
      }
      array[j + 1] = currentValue;
   }
   int x;
   for (x = 0; x < n; x++)
   {
      printf("%d ", array[x]);
   }
   printf("| \n");
}

// helper function to print the array
void printArray(int array[], int n, int split)
{
   int i;
   for (i = 0; i < n; i++)
   {
      if (i == split)
      {
         printf("| ");
      }
      printf("%d ", array[i]);
   }
   printf("\n");
}
