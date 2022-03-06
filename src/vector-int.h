//========================================================================
// vector-int.h
//========================================================================
// Interfaces for resizable vector

#ifndef VECTOR_INT_H
#define VECTOR_INT_H

#include <stddef.h>  // for size_tt

typedef struct {
  int*   data;
  size_t maxsize;
  size_t size;
} vector_int_t;

void   vector_int_construct( vector_int_t* this );
void   vector_int_destruct( vector_int_t* this );
size_t vector_int_size( vector_int_t* this );
void   vector_int_push_back( vector_int_t* this, int value );
int    vector_int_at( vector_int_t* this, size_t idx );
int    vector_int_contains( vector_int_t* this, int value );
int    vector_int_find_closest( vector_int_t* this, int value );
void   vector_int_sort( vector_int_t* this );
void   vector_int_print( vector_int_t* this );

//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#endif  // VECTOR_INT_H
