//========================================================================
// qsort-int.h
//========================================================================
// Declarations for quick sort

#ifndef QSORT_INT_H
#define QSORT_INT_H

#include <stddef.h>

size_t partition( int* a, size_t begin, size_t end, size_t size );
void   qsort_int( int* a, size_t size );

#endif  // QSORT_INT_H
