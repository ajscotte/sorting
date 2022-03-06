//========================================================================
// msort-int-directed-test.c
//========================================================================
// This file contains the tests for the merge sort function

#include "ece2400-stdlib.h"
#include "msort-int.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Simple test case for the selection sort function. One has zero size so it
// does nothing to array
// second sorts simple array

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {11, 7};
  msort_int( arr, 0 );
  ECE2400_CHECK_INT_EQ( arr[0], 11 );
  ECE2400_CHECK_INT_EQ( arr[1], 7 );
  msort_int( arr, 2 );
  ECE2400_CHECK_INT_EQ( arr[0], 7 );
  ECE2400_CHECK_INT_EQ( arr[1], 11 );
}

//------------------------------------------------------------------------
// test_case_2_empty_array_and_one_element
//------------------------------------------------------------------------
// Tests for an ampty array and an array of only one element
void test_case_2_empty_array_and_one_element()
{
  printf( "\n%s\n", __func__ );

  int* arr = NULL;
  msort_int( arr, 0 );

  int array[] = {2};

  msort_int( array, 1 );

  ECE2400_CHECK_INT_EQ( array[0], 2 );
}

//------------------------------------------------------------------------
// test_case_3_already_sorted
//------------------------------------------------------------------------
// Tests to see that the algorithm doesn;t do anything to already sorted array
void test_case_3_already_sorted()
{
  printf( "\n%s\n", __func__ );
  int array[40];
  int size = 40;

  for ( int i = 0; i < size; i++ ) {
    array[i] = i;
  }

  msort_int( array, size );

  for ( int i = 0; i < size; i++ ) {
    ECE2400_CHECK_INT_EQ( array[i], i );
  }
}

//------------------------------------------------------------------------
// test_case_4_double_values()
//------------------------------------------------------------------------
// Tests arrays that have multiple of the same value
// Author Alexander Scotte (ajs667)
void test_case_4_double_values()
{
  printf( "\n%s\n", __func__ );

  int array1[] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  int array2[] = {0, 1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 0};
  int array3[] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};

  msort_int( array1, 12 );
  msort_int( array2, 12 );
  msort_int( array3, 12 );
  for ( int i = 0; i < 6; i++ ) {
    ECE2400_CHECK_INT_EQ( array1[i * 2], i );
    ECE2400_CHECK_INT_EQ( array2[i * 2], i );
    ECE2400_CHECK_INT_EQ( array3[i * 2], i );
    ECE2400_CHECK_INT_EQ( array1[( i * 2 ) + 1], i );
    ECE2400_CHECK_INT_EQ( array2[( i * 2 ) + 1], i );
    ECE2400_CHECK_INT_EQ( array3[( i * 2 ) + 1], i );
  }
}

//------------------------------------------------------------------------
// test_case_5_non_even_size()
//------------------------------------------------------------------------
// Tests an array that has an odd number of values
void test_case_5_non_even_size()
{
  printf( "\n%s\n", __func__ );

  int array[] = {0, 10, 1, 2, 9, 3, 8, 4, 7, 5, 6};

  msort_int( array, 11 );

  for ( int i = 0; i < 11; i++ ) {
    ECE2400_CHECK_INT_EQ( array[i], i );
  }

  int array2[] = {11, 15, 16, 20, 21, 23, 24, 2, 5};

  msort_int( array2, 9 );

  ECE2400_CHECK_INT_EQ( array2[0], 2 );
  ECE2400_CHECK_INT_EQ( array2[1], 5 );
  ECE2400_CHECK_INT_EQ( array2[2], 11 );
  ECE2400_CHECK_INT_EQ( array2[3], 15 );
  ECE2400_CHECK_INT_EQ( array2[4], 16 );
  ECE2400_CHECK_INT_EQ( array2[5], 20 );
  ECE2400_CHECK_INT_EQ( array2[6], 21 );
  ECE2400_CHECK_INT_EQ( array2[7], 23 );
  ECE2400_CHECK_INT_EQ( array2[8], 24 );
}

//------------------------------------------------------------------------
// test_case_6_negative_values()
//------------------------------------------------------------------------
// Tests if negative values are ordered correctly
void test_case_6_negative_values()
{
  printf( "\n%s\n", __func__ );

  int array[] = {-3, -5, -1, -6};

  msort_int( array, 4 );
  ECE2400_CHECK_INT_EQ( array[0], -6 );
  ECE2400_CHECK_INT_EQ( array[1], -5 );
  ECE2400_CHECK_INT_EQ( array[2], -3 );
  ECE2400_CHECK_INT_EQ( array[3], -1 );
  int array2[40] = {0};
  for ( int i = 0; i > -21; i-- ) {
    array2[-2 * i]         = i;
    array2[( -2 * i ) + 1] = ( i * -1 );
  }

  msort_int( array2, 40 );

  for ( int i = -19; i < 0; i++ ) {
    ECE2400_CHECK_INT_EQ( array2[19 + i], i );
  }
  for ( int i = 0; i < 20; i++ ) {
    ECE2400_CHECK_INT_EQ( array2[20 + i], i );
  }
}

//------------------------------------------------------------------------
// test_case_7_reverse_sort()
//------------------------------------------------------------------------
// The case when array is from max to min not min to max
void test_case_7_reverse_sort()
{
  printf( "\n%s\n", __func__ );
  int array[100];
  for ( int i = 100; i > 0; i-- ) {
    array[100 - i] = i;
  }

  msort_int( array, 100 );

  for ( int i = 1; i < 101; i++ ) {
    ECE2400_CHECK_INT_EQ( array[i - 1], i )
  }
}

//------------------------------------------------------------------------
// test_case_8_very_large_array()
//------------------------------------------------------------------------
// tests to see if sorting algorithm can handle a large array
void test_case_8_very_large_array()
{
  printf( "\n%s\n", __func__ );
  int array[10000];
  for ( int i = 1; i < 5001; i++ ) {
    array[( 2 * ( i - 1 ) )]     = -1 * i;
    array[( 2 * ( i - 1 ) + 1 )] = i * 30;
  }

  msort_int( array, 10000 );

  for ( int i = -5000; i < 0; i++ ) {
    ECE2400_CHECK_INT_EQ( array[5000 + i], i );
  }
  for ( int i = 1; i < 5001; i++ ) {
    ECE2400_CHECK_INT_EQ( array[4999 + i], i * 30 )
  }
}

//------------------------------------------------------------------------
// test_case_9_extreme_elements
//------------------------------------------------------------------------
// Author: Olivia McGoldrick
// Test case for the selection sort function on an array with MAX and MIN
// values. Also tests msort with repeated elements.

void test_case_9_extreme_elements()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {INT_MAX, INT_MAX, INT_MAX, 10000, INT_MAX, INT_MIN, INT_MIN};
  msort_int( arr, 7 );
  ECE2400_CHECK_INT_EQ( arr[0], INT_MIN );
  ECE2400_CHECK_INT_EQ( arr[1], INT_MIN );
  ECE2400_CHECK_INT_EQ( arr[2], 10000 );
  ECE2400_CHECK_INT_EQ( arr[3], INT_MAX );
  ECE2400_CHECK_INT_EQ( arr[4], INT_MAX );
  ECE2400_CHECK_INT_EQ( arr[5], INT_MAX );
  ECE2400_CHECK_INT_EQ( arr[6], INT_MAX );
}

//------------------------------------------------------------------------
// test_case_10_exhaustive_array_sizes()
//------------------------------------------------------------------------
// This should be one of your last directed test cases! This test case
// only makes sense once you have passed many simpler test cases. For
// example, you will want simpler test cases with zero-sized arrays, a
// non-power of two elements, reverse sorted order, etc. This is an
// example of _exhaustive_ testing which tests every possible input value
// in some range. Here we are trying every array size from 0 to 33. This
// will really make sure we stress test recursive algorithms like
// mergesort and quicksort which might have corner cases related to odd
// or non-power of two array sizes.
//
// Author: Christopher Batten

void test_case_10_exhaustive_array_sizes()
{
  printf( "\n%s\n", __func__ );

  // try every size from 0 to 33

  for ( size_t size = 0; size < 33; size++ ) {
    ECE2400_DEBUG( "testing with size = %lu", size );

    // need to use malloc since size is a variable

    int* a = ece2400_malloc( size * sizeof( int ) );

    // fill the array with values from 0 to size-1 in reverse order

    for ( size_t i = 0; i < size; i++ )
      a[i] = size - i - 1;

    // sort the array

    msort_int( a, size );

    // verify the array is now in sorted order

    for ( size_t i = 0; i < size; i++ )
      ECE2400_CHECK_INT_EQ( a[i], i );

    // every malloc must have a free!

    ece2400_free( a );
  }
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n <= 0 ) || ( __n == 1 ) )
    test_case_1_simple();
  if ( ( __n <= 0 ) || ( __n == 2 ) )
    test_case_2_empty_array_and_one_element();
  if ( ( __n <= 0 ) || ( __n == 3 ) )
    test_case_3_already_sorted();
  if ( ( __n <= 0 ) || ( __n == 4 ) )
    test_case_4_double_values();
  if ( ( __n <= 0 ) || ( __n == 5 ) )
    test_case_5_non_even_size();
  if ( ( __n <= 0 ) || ( __n == 6 ) )
    test_case_6_negative_values();
  if ( ( __n <= 0 ) || ( __n == 7 ) )
    test_case_7_reverse_sort();
  if ( ( __n <= 0 ) || ( __n == 8 ) )
    test_case_8_very_large_array();
  if ( ( __n <= 0 ) || ( __n == 9 ) )
    test_case_9_extreme_elements();
  if ( ( __n <= 0 ) || ( __n == 10 ) )
    test_case_10_exhaustive_array_sizes();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your directed test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  printf( "\n" );
  return __failed;
}