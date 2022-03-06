//========================================================================
// vector-int-adhoc.c
//========================================================================
// This file contains an ad-hoc test for vector-related functions

#include "vector-int.h"
#include <stdio.h>

int main()
{
  vector_int_t vec;
  vector_int_construct( &vec );
  vector_int_push_back( &vec, 14 );
  vector_int_push_back( &vec, 42 );
  vector_int_push_back( &vec, 6 );

  vector_int_sort( &vec );

  printf( "Value stored at index 0 is %d\n", vector_int_at( &vec, 0 ) );
  printf( "Value stored at index 1 is %d\n", vector_int_at( &vec, 1 ) );
  printf( "Value stored at index 2 is %d\n", vector_int_at( &vec, 2 ) );

  vector_int_destruct( &vec );

  return 0;
}
