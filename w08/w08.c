/*******************************************
 * Id: lass2922
 *
 * Brute force string match algorithm
 *******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bruteForceStringMatch(char *P, int pSize, char *T, int tSize);

// Main function
int main (int argc, char *argv[])
{
   int mPattern = strlen(argv[1]);
   int nText = strlen(argv[2]);
   char *P = argv[1]; // Pattern
   char *T = argv[2]; // Text to search

   bruteForceStringMatch(P, mPattern, T, nText);
   printf("\n");

   return 0;
}

// Brute force function 
void bruteForceStringMatch(char *P, int mPattern, char *T, int nText)
{
   int i, j;

   printf("Matches found at locations:");

   for (i = 0; i < (nText - mPattern); i++)
   {
      j = 0;
      while (j < mPattern && P[j] == T[i + j])
      {
         j = j + 1;
      }
      if (j == mPattern)
      {
         printf(" %d", i);
      }
   }
}
