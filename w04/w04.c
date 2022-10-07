/**********************************************************
 * Id: lass2922
 *
 * Gaussian Elimination program to solve linear equations
 **********************************************************/ 

#include <stdlib.h>
#include <stdio.h>

void printMatrix(int n, float array[n][n+1]);

// Main function
int main(int argc, char* argv[])
{
   if (argc <= 2)
   {
      printf("%s more input required on command line \n", argv[0]);
      printf("%s Example:  3 1 2 3 4 5 6 7 8 9 10 11 12\n", argv[0]);
   }

   int n = atoi(argv[1]);
   int i,j;
   int k = 2;
   float tempji;
   float array[n][n+1];

   for (i = 0; i < n; i++)
   {
      for (j = 0;j < n+1; j++)
      {
         array[i][j] =  atof(argv[k]);
         k++;
      }
   }

   printMatrix(n, array);

   int x,y,z;

   for (x = 0; x < n; x++)
   {
      for (y = x+1; y < n+1; y++)
      {
         tempji = array[y][x];
         for (z = x; z < n+1; z++)
         {
            array[y][z] = array[y][z] - (array[x][z] * tempji / array[x][x]);
         }
      } 
      printMatrix(n, array);
   }
   return 0;
}

//Function to print matrix
void printMatrix(int n, float array[n][n+1])
{
   int i, j;

   for (i = 0; i < n; i++)
   {
      for(j = 0; j < n+1; j++)
      {
         printf("%.2f ", array[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}
