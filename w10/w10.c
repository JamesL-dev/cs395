/*****************************************************
 * Id: lass2922
 *
 * This is a quicksort program using Hoare Partition
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int low, int high, int arraySize);
void quickSort(int array[], int low, int hight, int arraySize);
int hoarePartition(int array[], int left, int right);

// Main function to run program
int main(int argc, char *argv[])
{
   int arraySize = argc - 1;
   int array[arraySize];

   // populate array from command line input
   int i;
   for (i = 0; i < arraySize; i++)
   {
      array[i] = atoi(argv[i + 1]);
   }

   quickSort(array, 0, arraySize-1, arraySize);
   printArray(array, 0, arraySize-1, arraySize);

   return 0;

}

// Function used to pring the array;
void printArray(int array[], int low, int high, int arraySize)
{
   int i;
   for (i = 0; i < arraySize; i++)
   {
      if (i == low)
      {
         printf("[%d ", array[i]);
      }
      else if (i == high)
      {
         printf("%d]  ", array[i]);
      }
      else
      {
         printf("%d ", array[i]);
      }
   }
   printf("\n");
}

// Handy dandy quicksort function
void quickSort(int array[], int low, int high, int arraySize)
{
   if (low < high)
   {
      int split = hoarePartition(array, low, high);

      quickSort(array, low, split - 1, arraySize);
      quickSort(array, split + 1, high, arraySize);
      printArray(array, low, high, arraySize);
   }
}

// Hoare partition used to split the array at a pivot point
int hoarePartition(int array[], int low, int high)
{
   int piv = array[low];
   int i = low;
   int j = high+1;

   
   while(1)
   {
      do
      {
         i++;
      }
      while(array[i] < piv);
      do
      {
         j--;
      }
      while(array[j] > piv);

      int tempI = array[i];
      array[i] = array[j];
      array[j] = tempI;

      if(i >= j)
      {
         break;
      }
   }
   int tempI = array[i];
   array[i] = array[j];
   array[j] = tempI;

   int tempJ = array[j];
   array[j] = array[low];
   array[low] = tempJ;

   return j;
}
