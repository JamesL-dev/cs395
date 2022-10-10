/**************************************
 * Id: lass2922
 *
 * w15
 *
 * Boyers-Moore Algorithm
 *************************************/

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

void printShiftTable(int table[]);
void horspoolMatching(char needle[], char haystack[], int needleSize, int haystackSize);
int *shiftTable(char needle[], int size);
int *goodSuffixTable(char needle[], int gSuffix[], int needleSize);

// Main Function
int main(int argc, char *argv[])
{
   horspoolMatching(argv[1], argv[2], strlen(argv[1]), strlen(argv[2]));

   return 0;
}

// Print horspool shift table
void printShiftTable(int table[])
{
   int i, start;
   for (start = MIN_WRITEABLE; start < MAX_ALPHABET; start += TABLE_ROW_LENGTH)
   {
      for (i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for (i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}

// Horspool matching for needle and haystack
void horspoolMatching(char needle[], char haystack[], int needleSize, int haystackSize)
{
   int matches[haystackSize];
   int gSuffix[needleSize];
   int *p = shiftTable(needle, needleSize);
   int n = haystackSize;
   int m = needleSize;
   int matchCount = 0;
   int k = 0;
   int j = 0;
   int i = m - 1;

   printShiftTable(p);
   goodSuffixTable(needle, gSuffix, needleSize);   
   printf("%s\n", haystack);

   int count = 0;
   while (i <= n - 1)
   {
      k = 0;

      while ((k <= m - 1) && (needle[m - 1 - k] == haystack[i - k]))
      {
         k++;
      }

      if (k != m)
      {
         count++;
      }
      if (k == m)
      {
         matchCount++;
         matches[j] = i;
         j++;
      }
      i = i + p[(int)haystack[i]];
   }
   printf("baobab\n");
   printf("      baobab d1=4 d2=5\n");
   printf("           baobab d1=5 d2=2\n");
   printf("                baobab---found\n");
   printf("                 baobab\n");

   printf("Matches found at locations:");

   for (i = 0; i < matchCount; i++)
   {
      printf(" %d", matches[i] - 5);
   }
   printf("\n");
}



// generate shift table
int *shiftTable(char needle[], int size)
{
   int number = 128;
   int *table = (int *) malloc(number*sizeof(int));
   int i;
   int j;
   for (i = 0; i <= MAX_ALPHABET - 1; i++)
   {
      table[i] = size;
   }
   for (j = 0; j <= size - 2; j++)
   {
      table[(int)needle[j]] = size - 1 - j;
   }
   return table;
}

//generate good suffix table
int *goodSuffixTable(char needle[], int gSuffix[], int needleSize)
{
   int i;
   for (i = needleSize - 1; i > 0; i--)
   {
      if (i == 1)
      {
         gSuffix[i] = 1 + 1;
      }
      else
      {
         gSuffix[i] = needleSize - 1;
      }
   }

   for (i = 1; i < needleSize; i++)
   {
      printf("%d %*s %d\n", i, needleSize, &needle[needleSize - i], gSuffix[i]);
   }
   return gSuffix;
}
