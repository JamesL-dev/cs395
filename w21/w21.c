/********************************************************
 * Id: lass2922
 *
 * This program takes a single integer as input (n)
 * and returns all permutations of the characters
 * from 1 to n each on its own line.
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>

void getPerms(int *numArray, int n, int a);
void swap(int *numArray, int i, int j);
void printArray(int *numArray, int length);

// Main Function
int main(int argc, char *argv[])
{
   int length = atoi(argv[1]);
   int numArray[length];
   
   int i;
   for (i = 1; i <= length; i++) // Fill the array with integers
   {
      numArray[i] = i;
   }
   
   getPerms(numArray, length, 1);

   return 0;

   
}

// Function thats finds and prints permutations of input
void getPerms(int *numArray, int length, int cid)
{
   int j;
   if(cid == length)
   {
      printArray(numArray, length);
      printf("\n");
      return;
   }
   for (j = cid; j <= length; j++)
   {
      swap(numArray, j, cid);
      getPerms(numArray, length, cid + 1);
      swap(numArray, j, cid);
   }
}

// Helper function to swap elements of the array around
void swap(int *numArray, int i, int j)
{
   int temp;
   temp = numArray[i];
   numArray[i] = numArray[j];
   numArray[j] = temp;
}

// Helper function to print the array
void printArray(int *numArray, int length)
{
   int x;
   for (x = 1; x <= length; x++)
   {
      printf("%d", numArray[x]);
   }
}
