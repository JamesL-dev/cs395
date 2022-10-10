/***********************************
 * Id: lass2922
 *
 * Horspools algorithm
 **********************************/

#include <stdio.h>
#include <stdlib.h>

int* shiftTable(char needle[], int m);
int horspoolMatching(char needle[], char haystack[], int m, int n);
void printShiftTable(int table[]);

// Main function
int main(int argc, char *argv[])
{
   int i = 0;
   while(1)
   {
      if (argv[1][i] == '\0')
      {
         break;
      }
      i++;
   }

   int z = 0;
   while(1)
   {
      if (argv[2][z] == '\0')
      {
         break;
      }
      z++;
   }
   horspoolMatching(argv[1], argv[2], i ,z);
   return 0; 
}

// Fill Shift table
int* shiftTable(char needle[], int m)
{
   int size = 128;
   int i;
   int* table = (int *) malloc(size*sizeof(int));
   for (i = 0; i < size; i++)
   {
      table[i] = m;
   }

   int j;
   for (j = 0; j < m - 1; j++)
   {
      table[(int) needle[j]] = m - 1 - j;
   }
   printShiftTable(table);
   return table;
}

// Horspool matching alg
int horspoolMatching(char needle[], char haystack[], int m, int n)
{
   int* table = shiftTable(needle, m);
   int matches[n];
   int matchNum = 0;
   printf("%s\n", haystack);
   int i = m-1;
   while (i <= n-1)
   {
      int k = 0;
      while (k <= m-1 && needle[m-1-k] == haystack[i-k])
      {
         k++;
      }
      if (k == m)
      {
         printf("%*s%s---found\n", i-m+1,"", needle);
         matches[matchNum] = i-m+1;
         matchNum++;
      }
      else
      {
         printf("%*s%s\n", i-m+1,"", needle);
      }  
      i += table[(int) haystack[i]];
   }
   printf("Matches found at locations:");
   int z;
   for(z = 0; z < matchNum; z++)
   {
      printf(" %d", matches[z]);
   }
   printf("\n");
   return -1;
}

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32
//print shift table
void printShiftTable(int table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start <  MAX_ALPHABET; start+=TABLE_ROW_LENGTH)
   {
      for (i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}
