//========================================================================
// ssort-int.c
//========================================================================
// Implementation of the selection sort function
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include "ssort-int.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------------------------
// find_min
//------------------------------------------------------------------------
// find the index of the minimum number in the array.

size_t find_min( int* a, size_t begin, size_t end, size_t size )
{
  assert( ( end - begin == size ) && ( begin < end ) );
  int min       = a[begin];
  int min_index = begin;

  // searches through array one element at a time to find the minimum value
  for ( size_t i = begin + 1; i < end; i++ ) {
    if ( min > a[i] ) {
      min       = a[i];
      min_index = i;
    }
  }

  return min_index;
}

//------------------------------------------------------------------------
// ssort_int
//------------------------------------------------------------------------
// Sorts the array with selection sort

void ssort_int( int* a, size_t size )
{
  size_t compare_index = 0;
  size_t min_index;
  int    temp;
  // first variable uses find_min to find the minimum index
  for ( size_t i = 1; i < size; i++ ) {
    min_index = find_min( a, i, size, size - i );

    // switchs values if initial value is larger than new value
    if ( a[compare_index] > a[min_index] ) {
      temp             = a[min_index];
      a[min_index]     = a[compare_index];
      a[compare_index] = temp;
    }

    compare_index++;
  }
}
