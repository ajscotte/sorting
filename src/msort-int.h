//========================================================================
// msort-int.h
//========================================================================
// Declarations for merge sort

#ifndef MSORT_INT_H
#define MSORT_INT_H

#include <stddef.h>

void merge( int* dst, int* src0, size_t begin0, size_t end0, size_t size0,
            int* src1, size_t begin1, size_t end1, size_t size1 );

void msort_int( int* a, size_t size );

#endif  // MSORT_INT_H
