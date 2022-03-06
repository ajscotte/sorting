//========================================================================
// qsort-int-whitebox-test.c
//========================================================================
// This file contains the whitebox tests for the quick sort implementation

#include "ece2400-stdlib.h"
#include "qsort-int.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Simple test case for the helper function.

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );

  size_t size = 8;
  int    a[]  = {1, 9, 9, 5, 0, 4, 2, 3};
  size_t p    = partition( a, 0, size, size );
  // Check if elements to the left of pivot is not greater than the pivot
  for ( size_t i = 0; i < p; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[p] );
  }
  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ ) {
    ECE2400_CHECK_TRUE( a[i] >= a[p] );
  }
}

//------------------------------------------------------------------------
// test_case_2_reverse_order
//------------------------------------------------------------------------
// tests if partition can handle decreasing array in integer value
void test_case_2_reverse_order()
{
  printf( "\n%s\n", __func__ );
  size_t size = 8;
  int    a[]  = {8, 7, 6, 5, 4, 3, 2, 1};
  size_t p    = partition( a, 0, size, size );
  for ( size_t i = 0; i < p; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[p] );
  }
  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ ) {
    ECE2400_CHECK_TRUE( a[i] >= a[p] );
  }
  p = partition( a, 1, size, size - 1 );
  for ( size_t i = 1; i < p; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[p] );
  }
  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ ) {
    ECE2400_CHECK_TRUE( a[i] >= a[p] );
  }
}

//------------------------------------------------------------------------
// test_case_3_same_element
//------------------------------------------------------------------------
// tests to see if partition can handle same elements in an array
void test_case_3_same_element()
{
  printf( "\n%s\n", __func__ );
  size_t size = 7;
  int    a[]  = {1, 1, 1, 1, 1, 1, 1};
  size_t p    = partition( a, 0, size, size );
  // Check if elements to the left of pivot is not greater than the pivot
  for ( size_t i = 0; i < p; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[p] );
  }
  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ ) {
    ECE2400_CHECK_TRUE( a[i] >= a[p] );
  }
}

//------------------------------------------------------------------------
// test_case_4_negative
//------------------------------------------------------------------------
// tests to see if partition can handle negative value in array
void test_case_4_negative()
{
  printf( "\n%s\n", __func__ );
  size_t size = 4;
  int    a[]  = {-1, -4, -3, -2};
  size_t p    = partition( a, 0, size, size );
  // Check if elements to the left of pivot is not greater than the pivot
  for ( size_t i = 0; i < p; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[p] );
  }
  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ ) {
    ECE2400_CHECK_TRUE( a[i] >= a[p] );
  }
}

//------------------------------------------------------------------------
// test_case_5_negative_and_positive
//------------------------------------------------------------------------
// tests to see if partition can handle both negative and positive values in
// same array
void test_case_5_negative_and_positive()
{
  printf( "\n%s\n", __func__ );
  size_t size = 7;
  int    a[]  = {-8, 8, -7, 7, 10, -10, -5, 5};
  size_t p    = partition( a, 0, size, size );
  // Check if elements to the left of pivot is not greater than the pivot
  for ( size_t i = 0; i < p; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[p] );
  }
  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ ) {
    ECE2400_CHECK_TRUE( a[i] >= a[p] );
  }
}

//------------------------------------------------------------------------
// test_case_6_many_values
//------------------------------------------------------------------------
// tests to see if partition can handle large array
void test_case_6_many_values()
{
  printf( "\n%s\n", __func__ );
  size_t size = 100;
  int    a[100];
  for ( size_t i = 0; i < size; i++ ) {
    a[i] = i;
  }
  size_t p = partition( a, 0, size, size );
  // Check if elements to the left of pivot is not greater than the pivot
  for ( size_t i = 0; i < p; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[p] );
  }
  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ ) {
    ECE2400_CHECK_TRUE( a[i] >= a[p] );
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
    test_case_2_reverse_order();
  if ( ( __n <= 0 ) || ( __n == 3 ) )
    test_case_3_same_element();
  if ( ( __n <= 0 ) || ( __n == 4 ) )
    test_case_4_negative();
  if ( ( __n <= 0 ) || ( __n == 5 ) )
    test_case_5_negative_and_positive();
  if ( ( __n <= 0 ) || ( __n == 6 ) )
    test_case_6_many_values();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add other categories for directed testing here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  printf( "\n" );
  return __failed;
}
