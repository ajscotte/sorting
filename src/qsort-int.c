//========================================================================
// qsort-int.c
//========================================================================
// Implementation of the quick sort function
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include "qsort-int.h"
#include <assert.h>
//------------------------------------------------------------------------
// partition
//------------------------------------------------------------------------
// Helper functino for quick_sort.

size_t partition( int* a, size_t begin, size_t end, size_t size )
{
  assert( ( end - begin == size ) && ( begin <= end ) );
  // create variables to hold values that will be needed throughout function
  // printf("Im here");
  int    pivot = a[end - 1];
  size_t index = begin;
  int    temp;

  // loops through array to create a lower and upper partition by swapping
  // specific values
  for ( size_t i = begin; i < end; i++ ) {
    // statement that compares current value in array to pivot to see
    // if it needs to be relocated to lower partition
    // swaps the current element with the lowest
    // index that hasn't already been swapped
    if ( a[i] <= pivot ) {
      temp     = a[index];
      a[index] = a[i];
      a[i]     = temp;
      index++;
    }
  }
  return index - 1;
}

void qsort_int_h( int* a, size_t begin, size_t end )
{
  // base case when the begin index is equal to the end index array is only one
  // number
  // one number is sorted
  if ( begin >= end ) {
  }
  // recursive case divides array lower and upper partitions
  else {
    int part = partition( a, begin, end, end - begin );
    qsort_int_h( a, begin, part );
    qsort_int_h( a, part + 1, end );
  }
}

//------------------------------------------------------------------------
// qsort_int
//------------------------------------------------------------------------
// Sorts the array with quick sort.

void qsort_int( int* a, size_t size )
{
  // pass array to recursive helper function
  qsort_int_h( a, 0, size );
}
