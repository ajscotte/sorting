//========================================================================
// vector-int.c
//========================================================================
// Baseline implementation of the vector functions
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include "vector-int.h"
#include "ece2400-stdlib.h"
#include "msort-int.c"
#include "msort-int.h"
//------------------------------------------------------------------------
// vector_int_construct
//------------------------------------------------------------------------
// Construct the vector_int_t and initialize the fields inside

void vector_int_construct( vector_int_t* this )
{
  // assert( this != NULL );
  // ECE2400_DEBUG( "vector_int_construct(%p) called!", this );
  // initializes vector
  this->data    = NULL;
  this->maxsize = 0;
  this->size    = 0;
}

//------------------------------------------------------------------------
// vector_int_destruct
//------------------------------------------------------------------------
// Destruct the vector_int_t, freeing any dynamically allocated memory if
// necessary

void vector_int_destruct( vector_int_t* this )
{
  // assert( this != NULL );
  // ECE2400_DEBUG( "vector_int_destruct(%p) called!", this );
  ece2400_free( this->data );
}

//------------------------------------------------------------------------
// vector_int_size
//------------------------------------------------------------------------
// Get the number of elements in the vector.

size_t vector_int_size( vector_int_t* this )
{
  // assert( this != NULL );
  // ECE2400_DEBUG( "vector_int_size(%p) called!", this );
  // returns size
  return this->size;
}

//------------------------------------------------------------------------
// vector_int_push_back
//------------------------------------------------------------------------
// Push a new value into the vector_int_t.

void vector_int_push_back( vector_int_t* this, int value )
{
  // assert( this != NULL );
  // ECE2400_DEBUG( "vector_int_push_back_v1(%p, %d) called!", this, value );
  // case if the entire vector is filled
  if ( this->size == this->maxsize ) {
    int* storage     = ece2400_malloc( ( this->size ) * sizeof( int ) );
    int  size_helper = this->size;
    // stores values in storage array
    for ( size_t i = 0; i < this->size; i++ ) {
      storage[i] = this->data[i];
    }
    // frees current vector
    ece2400_free( this->data );
    // makes new pointer to new array with increased size + 1
    this->data = ece2400_malloc( ( size_helper + 1 ) * sizeof( int ) );
    // inputs values back into vector
    for ( int i = 0; i < size_helper; i++ ) {
      this->data[i] = storage[i];
    }
    // increases size and max_size based on new vector size
    this->data[size_helper] = value;
    this->maxsize           = size_helper + 1;
    ece2400_free( storage );
  }
  // case if there is memory allocated for another value
  else {
    this->data[this->size] = value;
  }
  this->size++;
}

//------------------------------------------------------------------------
// vector_int_at
//------------------------------------------------------------------------
// Access the internal array and return the value at the given index
// If the index is out of bound, then return 0

int vector_int_at( vector_int_t* this, size_t idx )
{
   //assert( this != NULL );
  ECE2400_DEBUG( "vector_int_at(%p, %lu) called!", this, idx );
  if ( idx < this->size ) {
    // returns value at specific index
    return this->data[idx];
  }
  else {
    // returns 0 when idex out of bounds
    return 0;
  }
}

//------------------------------------------------------------------------
// vector_int_contains
//------------------------------------------------------------------------
// Search the vector for a value and return whether a value is found or
// not. Returning 1 means found, and 0 means not found.

int vector_int_contains( vector_int_t* this, int value )
{
  // assert( this != NULL );
  // ECE2400_DEBUG( "vector_int_contains(%p, %d) called!", this, value );
  for ( size_t i = 0; i < this->size; i++ ) {
    // returns 1 when value is present 0 if not
    if ( this->data[i] == value ) {
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------
// vector_int_find_closest
//------------------------------------------------------------------------
// Search the list for a value that is closest to the given value.
// If there are multiple values that are closest, return the one with the
// smallest index.
// Return -1 when the list is empty. Otherwise return the closest value.

int vector_int_find_closest( vector_int_t* this, int value )
{
  ECE2400_DEBUG( "vector_int_find_closest(%p, %d) called!", this, value );
  int size_helper = this->size;
  // case when vector data size is zero
  if ( size_helper == 0 ) {
    return -1;
  }

  int difference = this->data[0] - value;
  // case when difference is less than one
  if ( difference < 0 ) {
    difference = difference * -1;
  }
  int answer = this->data[0];
  // iterates over vector to compare value with current input values
  for ( size_t i = 0; i < this->size; i++ ) {
    int compare = this->data[i] - value;
    if ( compare < 0 ) {
      compare = compare * -1;
    }
    if ( difference > compare ) {
      difference = compare;
      answer     = this->data[i];
    }
  }
  return answer;
}

//------------------------------------------------------------------------
// vector_int_sort
//------------------------------------------------------------------------
// Sorts the internal data stored in the vector.

void vector_int_sort( vector_int_t* this )
{
  // inputs to msort_int
  msort_int( this->data, this->size );
}

//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//------------------------------------------------------------------------
// vector_int_print
//------------------------------------------------------------------------
// Print out the content of vector_int_t

void vector_int_print( vector_int_t* this ) {}
