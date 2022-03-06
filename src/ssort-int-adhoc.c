//========================================================================
// ssort-int-adhoc.c
//========================================================================

#include "ece2400-stdlib.h"
#include "ssort-int.h"
#include <stddef.h>
#include <stdio.h>

int main()
{
  size_t size = 4;
  int    a[]  = {19, 95, 4, 23};

  // Print out array before

  printf( "Before sorting: " );

  ece2400_print_array( a, size );

  // Call sort

  ssort_int( a, size );

  // Print out array after

  printf( "After sorting:  " );

  ece2400_print_array( a, size );

  return 0;
}
