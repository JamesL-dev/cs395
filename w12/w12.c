/*******************************************************
 * Id: lass2922
 *
 * This program compares insertion sort, selection sort
 * and quicksort.
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void selectionSort(int array[], int n);
int hoarePartition(int array[], int low, int hight);
void quickSort(int array[], int low, int high, int arraySize);
void insertionSort(int array[], int arraySize);

// Main function
int main(int argc, char *argv[])
{
   srand(0);

   int powerSize = 1;
   int y;
   int arraySize = 1;
   int arraySize2 = 100;
   int arraySize3 = 1000;
   for (y = 0; y < powerSize; y++)
   {
      arraySize *= 10;
   }
   int arrayOne[arraySize];
   int arrayTwo[arraySize];
   int arrayThree[arraySize];

   int arrayFour[arraySize2];
   int arrayFive[arraySize2];
   int arraySix[arraySize2];

   int arraySeven[arraySize3];
   int arrayEight[arraySize3];
   int arrayNine[arraySize3];

   int i;
   for (i = 0; i < arraySize; i++)
   {
      arrayOne[i] = rand() % 10;
   }

   for (i = 0; i < arraySize2; i++)
   {
      arrayFour[i] = rand() % 10;
   }

   for (i = 0; i < arraySize3; i++)
   {
      arraySeven[i] = rand() % 10;
   }

   int x;
   for (x = 0; x < arraySize; x++)
   {
      arrayTwo[x] = arrayOne[x];
      arrayThree[x] = arrayOne[x];
   }

   for (x = 0; x < arraySize2; x++)
   {
      arrayFive[x] = arrayFour[x];
      arraySix[x] = arrayFour[x];
   }

   for (x = 0; x < arraySize3; x++)
   {
      arrayEight[x] = arraySeven[x];
      arrayNine[x] = arraySeven[x];
   }

   struct timeval start, stop;
   gettimeofday(&start, NULL);
   selectionSort(arrayOne, arraySize);
   gettimeofday(&stop, NULL);
   double selectionTime = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   insertionSort(arrayTwo, arraySize);
   gettimeofday(&stop, NULL);
   double insertionTime = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   quickSort(arrayThree, 0, arraySize - 1, arraySize);
   gettimeofday(&stop, NULL);
   double quickTime = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   selectionSort(arrayFour, arraySize2);
   gettimeofday(&stop, NULL);
   double selectionTime2 = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   insertionSort(arrayFive, arraySize2);
   gettimeofday(&stop, NULL);
   double insertionTime2 = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   quickSort(arraySix, 0 , arraySize2 - 1, arraySize2);
   gettimeofday(&stop, NULL);
   double quickTime2 = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   selectionSort(arraySeven, arraySize3);
   gettimeofday(&stop, NULL);
   double selectionTime3 = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   insertionSort(arrayEight, arraySize3);
   gettimeofday(&stop, NULL);
   double insertionTime3 = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
   quickSort(arrayNine, 0, arraySize3 - 1, arraySize3);
   double quickTime3 = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   //printf("Selection sortTime: %f\nInsertion Sort Time: %f\nQuick Sort Time: %f\nNumber of Elements: %d\n", selectionTime, insertionTime, quickTime, arraySize);

   printf("+----------------------+----------------+-----------------+-----------+\n");
   printf("|   Number of Elements | Selection Sort | Inserstion Sort | Quicksort |\n");
   printf("+----------------------+----------------+-----------------+-----------+\n");
   printf("|                    %d|        %f|         %f|   %f|\n", arraySize, selectionTime, insertionTime, quickTime);
   printf("|                   %d|        %f|         %f|   %f|\n", arraySize2, selectionTime2, insertionTime2, quickTime2);
   printf("|                  %d|        %f|         %f|   %f|\n", arraySize3, selectionTime3, insertionTime3, quickTime3);
   printf("+----------------------+----------------+-----------------+-----------+\n");

   return 0;
}

// hoare partition to split for quicksort
int hoarePartition(int array[], int low, int high)
{
   int piv = array[low];

   int i = low;
   int j = high + 1;

   while(1)
   {
      do
      {
         i++;
      }
      while (array[i] < piv);
      do
      {
         j--;
      }
      while (array[j] > piv);

      int tempI = array[i];
      array[i] = array[j];
      array[j] = tempI;
      if (i >= j)
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

// selection sort function
void selectionSort(int array[], int n)
{
   int i, min;
   for(i = 0; i < n - 1; i++)
   {
      min = i;
      int j;
      for (j = i + 1; j < n; j++)
      {
         if (array[j] < array[min])
         {
            min = j;
         }
      }
      if (min != i)
      {
         int tempI = array[i];
         array[i] = array[min];
         array[min] = tempI;
      }
   }
}

// quicksort function
void quickSort(int array[], int low, int high, int arraySize)
{
   if (low < high)
   {
      int split = hoarePartition(array, low, high);
      quickSort(array, low, split-1, arraySize);
      quickSort(array, split+1, high, arraySize);
   }
}

// insertion sort function
void insertionSort(int array[], int arraySize)
{
   int i;
   for (i = 1; i < arraySize; i++)
   {
      int v = array[i];
      int j = i - 1;
      while (i >= 0 && array[j] > v)
      {
         array[j + 1] = array[j];
         j--;
      }
      array[j + 1] = v;
   }
}

//+----------------------+----------------+-----------------+-----------+
//|   Number of Elements | Selection Sort | Inserstion Sort | Quicksort |
//+----------------------+----------------+-----------------+-----------+
//|                    10|        0.001000|         0.000000|   0.001000|
//|                   100|        0.035000|         0.008000|   0.007000|
//|                  1000|        1.492000|         0.699000|   0.000000|
// +----------------------+----------------+-----------------+-----------+
