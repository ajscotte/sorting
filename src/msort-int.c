//========================================================================
// msort-int.c
//========================================================================
// Implementation of the merge sort function

#include "msort-int.h"
#include "ece2400-stdlib.h"
#include <assert.h>
//------------------------------------------------------------------------
// merge
//------------------------------------------------------------------------
// Helper function that merges two sorted arrays.

void merge( int* dst, int* src0, size_t begin0, size_t end0, size_t size0,
            int* src1, size_t begin1, size_t end1, size_t size1 )
{
  assert( ( end0 - begin0 == size0 ) && ( begin0 <= end0 ) );
  assert( ( end1 - begin1 == size1 ) && ( begin1 <= end1 ) );

  size_t index0   = begin0;
  size_t index1   = begin1;
  size_t dstIndex = 0;

  // goes through sorted array while values still have a comparison
  while ( index0 < end0 && index1 < end1 ) {
    // if src0 array has a smaller value than src1 array
    if ( src0[index0] < src1[index1] ) {
      dst[dstIndex] = src0[index0];
      index0++;
    }

    // src0[index0] >= src1[index1]
    else if ( src0[index0] >= src1[index1] ) {
      dst[dstIndex] = src1[index1];
      index1++;
    }
    dstIndex++;
  }

  // when src1 array has been used and only values left from src0 array
  if ( index0 != end0 ) {
    for ( size_t i = index0; i < size0; i++ ) {
      dst[dstIndex] = src0[i];
      dstIndex++;
    }
  }

  // when src0 array has been used and only values left from src1 array
  if ( index1 != end1 ) {
    for ( size_t i = index1; i < size1; i++ ) {
      dst[dstIndex] = src1[i];
      dstIndex++;
    }
  }
}

//------------------------------------------------------------------------
// pointer_helper
//------------------------------------------------------------------------
// allocates memory on heap for a pointer of end - start number of integers
// (array)
int* pointer_helper( int* this, size_t start, size_t end )
{
  // creates array on the heap that can be any values from input array
  int* result = ece2400_malloc( ( end - start ) * sizeof( int ) );

  // populates new array with a specified range from input array
  for ( size_t i = start; i < end; i++ ) {
    result[i - start] = this[i];
  }

  // returns array
  return result;
}

//------------------------------------------------------------------------
// msort_int
//------------------------------------------------------------------------
// Sorts the array with merge sort.

void msort_int( int* a, size_t size )
{
  // base case when size is 1 or less since array will be sorted in this case
  if ( size <= 1 ) {
  }

  // recursive case that continuously divides the array into smaller arrays
  else if ( size > 1 ) {
    size_t array_size1 = size / 2;
    size_t array_size2 = size - array_size1;

    // allocates memory for out of place arrays on heap
    int* array1 = pointer_helper( a, 0, array_size1 + 1 );
    int* array2 = pointer_helper( a, array_size1, size );

    // recursive statements to divide array
    msort_int( array1, array_size1 );
    msort_int( array2, array_size2 );

    // sorts arrays into big array after many recusive statements
    merge( a, array1, 0, array_size1, array_size1, array2, 0, array_size2,
           array_size2 );

    // frees arrays from the heap to avoid memeory leaks
    ece2400_free( array1 );
    ece2400_free( array2 );
  }
}
