/*******************************************************
 * Id: lass2922
 *
 * This program solves the Tower of Hanoi puzzle
 ******************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void hanoiSolver(int n, char fromRod, char toRod, char auxRod);

// Main Function
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   char charArray[4] = 
   {'A', 'B', 'C', '\0'
   };
   hanoiSolver(n, charArray[0], charArray[2], charArray[1]);

   return 0;
}

// Function to solve hanoi tower by shifting by 1
void hanoiSolver(int n, char fromRod, char toRod, char auxRod)
{
   if (n == 0)
   {
      return;
   }
   hanoiSolver(n - 1, fromRod, auxRod, toRod);
   printf("Move %c TO %c\n", fromRod, toRod);
   hanoiSolver(n - 1, auxRod, toRod, fromRod);
}
