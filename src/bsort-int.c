//========================================================================
// bsort-int.c
//========================================================================
// Implementation of the bucket sort function
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include "bsort-int.h"
#include "ece2400-stdlib.h"
#include "vector-int.c"
#include "vector-int.h"
//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Define K as the number of buckets
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
#define K 770
//------------------------------------------------------------------------
// bsort_max_h
//------------------------------------------------------------------------
// finds maximum value in input array
int bsort_max_h( int* a, size_t size )
{
  int max = a[0];
  // loops through array to find maximum value by comparing specific elements
  for ( size_t i = 0; i < size; i++ ) {
    if ( a[i] > max ) {
      max = a[i];
    }
  }

  // returns minimum value
  return max;
}

//------------------------------------------------------------------------
// bsort_max_h
//------------------------------------------------------------------------
// finds minimum value in input array
int bsort_min_h( int* a, size_t size )
{
  int min = a[0];
  // loops through array to find minimum value by comparing specific elements
  for ( size_t i = 0; i < size; i++ ) {
    if ( a[i] < min ) {
      min = a[i];
    }
  }

  // returns minimum value
  return min;
}

//------------------------------------------------------------------------
// bsort_int
//------------------------------------------------------------------------
// Sorts the array with bucket sort

void bsort_int( int* a, size_t size )
{
  // case for NULL pointer
  if ( size == 0 ) {
    return;
  }

  int           min          = bsort_min_h( a, size );
  int           max          = bsort_max_h( a, size );
  int           k            = 770;
  uint_t        bucket_range = 1 + distance_int( max, min ) / k;
  vector_int_t* buckets =
      (vector_int_t*) ece2400_malloc( k * sizeof( vector_int_t ) );
  // constructs k number of buckets to use for bucket sort
  for ( int i = 0; i < k; i++ ) {
    vector_int_construct( &buckets[i] );
  }

  int bucket_index = 0;
  // puts numbers in corresponding buckets
  for ( size_t i = 0; i < size; i++ ) {
    bucket_index = ( a[i] - min ) / bucket_range;
    vector_int_push_back( &buckets[bucket_index], a[i] );
  }

  // sorts each bucket
  for ( int i = 0; i < k; i++ ) {
    vector_int_sort( &buckets[i] );
  }

  int vector_size;
  int index = 0;
  // inserts values in each bucket back into original array in correct order
  for ( int i = 0; i < k; i++ ) {
    vector_size = vector_int_size( &buckets[i] );
    for ( int c = 0; c < vector_size; c++ ) {
      a[index] = vector_int_at( &buckets[i], c );
      index++;
    }
  }

  // destructs each bucket from the heap
  for ( int i = 0; i < k; i++ ) {
    vector_int_destruct( &buckets[i] );
  }

  // frees the list of vectors from the heap
  ece2400_free( buckets );
}
