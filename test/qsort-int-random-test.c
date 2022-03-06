//========================================================================
// qsort-int-random-tests.c
//========================================================================
// This file contains the random test casess for the quick sort
// function.

#include "ece2400-stdlib.h"
#include "qsort-int.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Simple test case that tests if a random array of size 10 can be sorted

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8BadBeef );

  int random;
  int a[10];
  int size = 10;
  // populates array with random values
  for ( int i = 0; i < size; i++ ) {
    random = rand() % 10;
    a[i]   = random;
  }
  // sorts array
  qsort_int( a, size );
  ece2400_print_array( a, size );
  // checks to see if array is sorted
  for ( int i = 0; i < size - 1; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[i + 1] );
  }
}

//------------------------------------------------------------------------
// test_case_2_double_values
//------------------------------------------------------------------------
// random case that test if sorting algorithm can handle random double values
void test_case_2_double_values()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8BadBeef );

  int random;
  int a[100];
  int size = 100;

  // populates array with random values
  for ( int i = 0; i < size / 2; i++ ) {
    random           = rand() % 100;
    a[2 * i]         = random;
    a[( 2 * i ) + 1] = random;
  }

  qsort_int( a, size );

  for ( int i = 0; i < size - 1; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[i + 1] );
  }
}

//------------------------------------------------------------------------
// test_case_3_negative_values
//------------------------------------------------------------------------
// random case that tests if sorting algorithm can handle negative values
void test_case_3_negative_values()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8BadBeef );

  int random;
  int a[100];
  int size = 100;
  // populates array with random values
  for ( int i = 0; i < size; i++ ) {
    random = -rand() % 1000 - 1;
    a[i]   = random;
  }
  // sorts array
  qsort_int( a, size );

  // checks to see if array is sorted
  for ( int i = 0; i < size - 1; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[i + 1] );
  }
}

//------------------------------------------------------------------------
// test_case_4_random size
//------------------------------------------------------------------------
// random case that tests a random array size that a sorting algorithm must sort
void test_case_4_random_size()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8BadBeef );

  int  random;
  int  random_size = rand() % 1000;
  int* a           = ece2400_malloc( random_size * sizeof( int ) );
  // populates array with random values
  for ( int i = 0; i < random_size; i++ ) {
    random = rand() % 1000;
    a[i]   = random;
  }
  // sorts array
  qsort_int( a, random_size );

  // checks to see if array is sorted
  for ( int i = 0; i < random_size - 1; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[i + 1] );
  }
  ece2400_free( a );
}

//------------------------------------------------------------------------
// test_case_5_very_large
//------------------------------------------------------------------------
// random case that tests if algorthm can handle large values near INT_MAX
void test_case_5_very_large_values()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8BadBeef );

  int random;
  int a[10000];
  int size = 10000;
  // populates array with random values
  for ( int i = 0; i < size; i++ ) {
    random = rand() % INT_MAX;
    a[i]   = random;
  }
  // sorts array
  qsort_int( a, size );

  // checks to see if array is sorted
  for ( int i = 0; i < size - 1; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[i + 1] );
  }
}

//------------------------------------------------------------------------
// test_case_6_large_array
//------------------------------------------------------------------------
// random case that tests if algorithm can handle a very array size
void test_case_6_large_array()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8BadBeef );

  int random;
  int a[10000];
  int size = 10000;
  // populates array with random values
  for ( int i = 0; i < size; i++ ) {
    random = rand() % 100;
    a[i]   = random;
  }
  // sorts array
  qsort_int( a, size );

  // checks to see if array is sorted
  for ( int i = 0; i < size - 1; i++ ) {
    ECE2400_CHECK_TRUE( a[i] <= a[i + 1] );
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
    test_case_2_double_values();
  if ( ( __n <= 0 ) || ( __n == 3 ) )
    test_case_3_negative_values();
  if ( ( __n <= 0 ) || ( __n == 4 ) )
    test_case_4_random_size();
  if ( ( __n <= 0 ) || ( __n == 5 ) )
    test_case_5_very_large_values();
  if ( ( __n <= 0 ) || ( __n == 6 ) )
    test_case_6_large_array();

  printf( "\n" );
  return __failed;
}
