//========================================================================
// ssort-int.h
//========================================================================
// Declarations for selection sort

#ifndef SSORT_INT_H
#define SSORT_INT_H

#include <stddef.h>

size_t find_min( int* a, size_t begin, size_t end, size_t size );
void   ssort_int( int* a, size_t size );

#endif  // SSORT_INT_H
