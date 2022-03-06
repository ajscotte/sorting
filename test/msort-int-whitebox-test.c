//========================================================================
// msort-int-whitebox-test.c
//========================================================================
// This file contains the whitebox tests for the merge sort implementation

#include "ece2400-stdlib.h"
#include "msort-int.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// test_case_1_same_len
//------------------------------------------------------------------------
// Simple test case for the helper function.

void test_case_1_same_len()
{
  printf( "\n%s\n", __func__ );
  int a[] = {19, 95};
  int b[] = {4, 23};

  int c[4] = {0};

  merge( c, a, 0, 2, 2, b, 0, 2, 2 );

  ECE2400_CHECK_INT_EQ( c[0], 4 );
  ECE2400_CHECK_INT_EQ( c[1], 19 );
  ECE2400_CHECK_INT_EQ( c[2], 23 );
  ECE2400_CHECK_INT_EQ( c[3], 95 );
}

//------------------------------------------------------------------------
// test_case_2_different_len
//------------------------------------------------------------------------
// Helper function test that different length arrays
void test_case_2_different_len()
{
  printf( "\n%s\n", __func__ );
  int d[]   = {1, 3, 5, 6, 7, 9, 11};
  int e[]   = {2, 4, 5};
  int c[10] = {0};

  merge( c, d, 0, 7, 7, e, 0, 3, 3 );
  ece2400_print_array( c, 10 );
  ECE2400_CHECK_INT_EQ( c[0], 1 );
  ECE2400_CHECK_INT_EQ( c[1], 2 );
  ECE2400_CHECK_INT_EQ( c[2], 3 );
  ECE2400_CHECK_INT_EQ( c[3], 4 );
  ECE2400_CHECK_INT_EQ( c[4], 5 );
  ECE2400_CHECK_INT_EQ( c[5], 5 );
  ECE2400_CHECK_INT_EQ( c[6], 6 );
  ECE2400_CHECK_INT_EQ( c[7], 7 );
  ECE2400_CHECK_INT_EQ( c[8], 9 );
  ECE2400_CHECK_INT_EQ( c[9], 11 );

  int b[]  = {1, 3, 4, 7, 11};
  int a[]  = {2, 4, 5};
  int f[8] = {0};

  merge( f, a, 0, 3, 3, b, 0, 7, 7 );
  ece2400_print_array( f, 8 );
  ECE2400_CHECK_INT_EQ( f[0], 1 );
  ECE2400_CHECK_INT_EQ( f[1], 2 );
  ECE2400_CHECK_INT_EQ( f[2], 3 );
  ECE2400_CHECK_INT_EQ( f[3], 4 );
  ECE2400_CHECK_INT_EQ( f[4], 4 );
  ECE2400_CHECK_INT_EQ( f[5], 5 );
  ECE2400_CHECK_INT_EQ( f[6], 7 );
  ECE2400_CHECK_INT_EQ( f[7], 11 );
}

//------------------------------------------------------------------------
// test_case_3_same_arrauy
//------------------------------------------------------------------------
// test case were both arrays are the same.
void test_case_3_same_array()
{
  printf( "\n%s\n", __func__ );
  int a[]  = {2, 4, 5};
  int b[]  = {2, 4, 5};
  int f[6] = {0};

  merge( f, a, 0, 3, 3, b, 0, 3, 3 );

  ECE2400_CHECK_INT_EQ( f[0], 2 );
  ECE2400_CHECK_INT_EQ( f[1], 2 );
  ECE2400_CHECK_INT_EQ( f[2], 4 );
  ECE2400_CHECK_INT_EQ( f[3], 4 );
  ECE2400_CHECK_INT_EQ( f[4], 5 );
  ECE2400_CHECK_INT_EQ( f[5], 5 );
}

//------------------------------------------------------------------------
// test_case_4_array_of_size_1
//------------------------------------------------------------------------
// Simple test case to see if function can handle arrays of size 1
void test_case_4_array_of_size_1()
{
  printf( "\n%s\n", __func__ );
  int a[]  = {2};
  int b[]  = {4};
  int f[2] = {0};

  merge( f, a, 0, 1, 1, b, 0, 1, 1 );
  ece2400_print_array( f, 2 );
  ECE2400_CHECK_INT_EQ( f[0], 2 );
  ECE2400_CHECK_INT_EQ( f[1], 4 );
}

//------------------------------------------------------------------------
// test_case_5_negative_values
//------------------------------------------------------------------------
// Tests arrays of negative and positive values
void test_case_5_negative_values()
{
  printf( "\n%s\n", __func__ );
  int a[]  = {-100, -80, -20, 20};
  int b[]  = {-90, -30, 40, 60};
  int f[8] = {0};
  merge( f, a, 0, 4, 4, b, 0, 4, 4 );
  ece2400_print_array( f, 8 );
  ECE2400_CHECK_INT_EQ( f[0], -100 );
  ECE2400_CHECK_INT_EQ( f[1], -90 );
  ECE2400_CHECK_INT_EQ( f[2], -80 );
  ECE2400_CHECK_INT_EQ( f[3], -30 );
  ECE2400_CHECK_INT_EQ( f[4], -20 );
  ECE2400_CHECK_INT_EQ( f[5], 20 );
  ECE2400_CHECK_INT_EQ( f[6], 40 );
  ECE2400_CHECK_INT_EQ( f[7], 60 );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n <= 0 ) || ( __n == 1 ) )
    test_case_1_same_len();
  if ( ( __n <= 0 ) || ( __n == 2 ) )
    test_case_2_different_len();
  if ( ( __n <= 0 ) || ( __n == 3 ) )
    test_case_3_same_array();
  if ( ( __n <= 0 ) || ( __n == 4 ) )
    test_case_4_array_of_size_1();
  if ( ( __n <= 0 ) || ( __n == 5 ) )
    test_case_5_negative_values();

  printf( "\n" );
  return __failed;
}