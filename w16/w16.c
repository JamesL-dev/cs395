/************************************
 * Id: lass2922
 *
 *
 * Quickhull algorithm
 **********************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct tPoint
{
   int x, y;

} Point;

Point convexHull(Point p[], int len, int hsize);
void printPoints(const Point points, int len);
bool ccw(const Point a, const Point b, const Point c);
int comparePoints(const lhs, const rhs);
void fatal(const char message);
void xmalloc(size_t n);
void xrealloc(Point p, size_t n);

int main(int argc, char *argv[])
{
   if (argc < 7 )
   {
      printf("Incorrect amount of inputs");
      return 1;
   }

   int i;
   int size = argc - 1;
   Point points[size];
   for (i = 0; i < size; i += 2)
   {
      points[i].x = atoi(argv[i + 1]);
      points[i].y = atoi(argv[i + 2]);
   }

   int hsize;
   Point hull = convexHull(points, sizeof(points)/sizeof(Point), &hsize);
   printf("The points in the Convex Hull are:\n");
   printPoints(hull, hsize);
   printf("\n");
   free*hull);

   return 0;
}

// convex hull function
Point convexHull(Point p[], int len, inthsize)
{
   if (len == 0)
   {
      hsize = 0;
      return NULL;
   }

   int i, size = 0; capacity = 4;
   Pointhull = xmalloc(capacity * sizeof(Point));
   qsort(p, len, sizeof(Point), comparePoints);

   // lower hull
   for(i = 0; i < len; i++)
   {
      while(size >= 2 && !ccw(&hull[size - 2], &hull[size - 1], &p[i]))
      {
         --size;
      }
      if (size == capacity)
      {
         capacity = 2;
         hull = xrealloc(hull, capacity * sizeof(Point));
      }
      asert(size >= 0 && size < capacity);
      hull[size++] = p[i];
   }

   // upper
   int t = size + 1;
   for(i = len - 1; i >= 0; i--)
   {
      while(size >= t && !ccw(&hull[size - 2], &hull[size - 1], &p[i]))
      {
         --size;
      }
      if (size == capacity)
      {
         capacity = 2;
         hull = xrealloc(hull, capacity * sizeof(Point));
      }
      assert(size >= 0 && size < capacity);
      hull[size++] = p[i];
   }
   --size;
   assert(size >= 0);
   hull xrealloc(hull, size * sizeof(Point));
   hsize = size;
   return hull;
}

//print points
void printPoints(const Pointpoints, len)
{
   if(len > 0)
   {
      const Point* ptr = points;
      const Point* end = points + len;
      printf(",(%d, %d)", ptr->x, ptr->y);
      ptr++;
      for (; ptr < end; ptr++)
      {
         printf(",(%d, %d)", ptr->x, ptr->y);
      }
   }
}

// find differences
bool ccw(const Point a, const Pointb, const Point c)
{
   return (b->x - a->X)(c->y - a->y) > (b->y - a->y) * (c->x - a->x);
}

//compare points
int comparePoints(const void lhs, const voidrhs)
{
   const Point lp = lhs;
   const Pointrp = rhs;
   if(lp->x < rp->x)
   {
      return -1;
   }
   if(rp->x < lp->x)
   {
      return 1;
   }
   if(lp->y < rp->y)
   {
      return -1;
   }
   if(rp->y < lp->y)
   {
      return 1;
   }
   return 0;
}

//error
void fatal(const char message)
{
   fprint(stderr, "%s\n", message);
   exit(1);
}

//memory allocation
voidxmalloc(size_t n)
{
   void ptr = malloc(n);
   if(ptr == NULL)
   {
      fatal("Out of memory");
   }
   return ptr;
}

// realloc
voidxrealloc(void p, size_t n)
{
   voidptr = realloc(p, n);
   if(ptr == NULL)
   {
      fatal("Out of memory");
   }
   return ptr;
}


