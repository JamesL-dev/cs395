/*******************************************************
 * Id: lass2922
 *
 * This program solves the Tower of Hanoi puzzle with
 * the restriction where A can't move to B
 ******************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void restrictedHanoi(int n, char fromRod, char toRod, char auxRod);

// Main Function
int main(int argc, char *argv[])
{
   if (argc < 1)
   {
      printf("%s requires at least 1 input", argv[0]);
   }
   int n = atoi(argv[1]);
   char charArray[4] = 
   {'A', 'B', 'C', '\0'
   };
   restrictedHanoi(n, charArray[0], charArray[1], charArray[2]);

   return 0;
}

// Function to recursively move disks around to solve hanoi tower
void restrictedHanoi(int n, char startRod, char midRod, char goalRod)
{
   if (n == 1)
   {
      printf("Move %c TO %c \n", startRod, midRod);
      printf("Move %c TO %c \n", midRod, goalRod);
      return;
   }
   restrictedHanoi(n - 1, startRod, midRod, goalRod);
   printf("Move %c TO %c\n", startRod, midRod);
   restrictedHanoi(n - 1, goalRod, midRod, startRod);
   printf("Move %c TO %c \n", midRod, goalRod);
   restrictedHanoi(n - 1, startRod, midRod, goalRod);
}
