/************************************************
 * Id: lass2922
 *
 * This program takes an integer input for a stack
 * for tower of hanoi. In this version A cannot move to B
 * All disks are moved to the last stack first
 ***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void cyclicHanoi(int i, char firstRod, char midRod, char goalRod);

// Main Function
int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("At least 1 integer input required");
   }
   int i = atoi(argv[1]);
   cyclicHanoi(i, 'A', 'C', 'B');

   return 0;
}

// Function to solve hanoi puzzle in a cyclic fashion!
void cyclicHanoi(int i, char firstRod, char goalRod, char midRod)
{
   if (i == 1)
   {
      printf("Move %c TO %c \n", firstRod, midRod);
      printf("Move %c TO %c \n", midRod, goalRod);
      return;
   }
   else if (i > 1)
   {
      cyclicHanoi(i-1, firstRod, goalRod, midRod);
      printf("Move %c TO %c \n", firstRod, midRod);
      cyclicHanoi(i-2, goalRod, midRod, firstRod);
      printf("Move %c TO %c \n", goalRod, firstRod);
      cyclicHanoi(i-2, midRod, firstRod, goalRod);
      printf("Move %c TO %c \n", midRod, goalRod);
      cyclicHanoi(i-1, firstRod, goalRod, midRod);
   }
}

