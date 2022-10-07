/**************************************
 * Id: lass2922
 *
 * This is a selection sort program
 **************************************/

#include <stdlib.h>
#include <stdio.h>

void printArray(int arr[], int n);
void selectionSort(int arr[], int n);

// Main Function
int main(int argc, char *argv[])
{
   int arraySize = argc-1;
   int array[arraySize];

   int i;
   for (i = 0; i < arraySize; i++)
   {
      array[i] = atoi(argv[i+1]);
   }
   printArray(array, arraySize);
   selectionSort(array, arraySize);
   printf("\n");
   return 0;
}

// Function to print out the array
void printArray(int arr[], int size)
{
   int i;
   for (i = 0; i < size; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

// Selection sort function
void selectionSort(int arr[], int n)
{
   int i, j, min;
   for (i = 0; i < n-1; i++)
   {
      min = i;
      for (j = i+1; j < n; j++)
      {
         if (arr[j] < arr[min])
         {
            min = j;
         }
      }
      if (min != i)
      {
         int temp = arr[i];
         arr[i] = arr[min];
         arr[min] = temp;
      }
      printArray(arr, n);
   }
}
