//========================================================================
// ssort-int-whitebox-test.c
//========================================================================
// This file contains the whitebox tests for the selection sort
// implementation

#include "ece2400-stdlib.h"
#include "ssort-int.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Simple test case for the helper function.

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {11, 7, 20, 0};
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 4, 4 ), 3 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 3, 3 ), 1 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 2, 2 ), 1 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 1, 1 ), 0 );
}

//------------------------------------------------------------------------
// test_case_2_min_first
//------------------------------------------------------------------------
// Test case that analyzes an array with the minimum in the first index
void test_case_2_min_first()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {0, 1, 2, 3, 4, 5};
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 5, 5 ), 0 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 1, 5, 4 ), 1 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 2, 5, 3 ), 2 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 3, 5, 2 ), 3 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 4, 5, 1 ), 4 );
}

//------------------------------------------------------------------------
// test_case_3_min_last
//------------------------------------------------------------------------
// Test case that analyzes an array with the minimum in the last index
//------------------------------------------------------------------------
void test_case_3_min_last()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {5, 4, 3, 2, 1, 0};
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 5, 5 ), 4 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 4, 4 ), 3 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 3, 3 ), 2 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 2, 2 ), 1 );
  ECE2400_CHECK_INT_EQ( find_min( arr, 0, 1, 1 ), 0 );
}

//------------------------------------------------------------------------
// test_case_4_large_array
//------------------------------------------------------------------------
// tests to see if find min can find minimum in a large array
void test_case_4_large_array()
{
  printf( "\n%s\n", __func__ );
  int array[100];
  for ( int i = 0; i < 100; i++ ) {
    array[i] = i;
  }

  for ( int i = 0; i < 100; i++ ) {
    ECE2400_CHECK_INT_EQ( find_min( array, i, 100, 100 - i ), i );
  }
}

//------------------------------------------------------------------------
// test_case_5_same_value
//------------------------------------------------------------------------
// Simple test case that test to see if find min can handle duplicate values
void test_case_5_same_value()
{
  printf( "\n%s\n", __func__ );
  int array[100];
  for ( int i = 0; i < 100; i++ ) {
    array[i] = 10;
  }

  for ( int i = 0; i < 100; i++ ) {
    ECE2400_CHECK_INT_EQ( find_min( array, i, 100, 100 - i ), i );
  }
}

//------------------------------------------------------------------------
// test_case_6_negative_values
//------------------------------------------------------------------------
// tests to see if function can handle negative values
void test_case_6_negative_values()
{
  printf( "\n%s\n", __func__ );
  int array[] = {10, 12, -5, -100, 12, 20};
  ECE2400_CHECK_INT_EQ( find_min( array, 0, 6, 6 ), 3 );
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
    test_case_2_min_first();
  if ( ( __n <= 0 ) || ( __n == 3 ) )
    test_case_3_min_last();
  if ( ( __n <= 0 ) || ( __n == 4 ) )
    test_case_4_large_array();
  if ( ( __n <= 0 ) || ( __n == 5 ) )
    test_case_5_same_value();
  if ( ( __n <= 0 ) || ( __n == 6 ) )
    test_case_6_negative_values();

  printf( "\n" );
  return __failed;
}