/**
 * @file psort.h
 */

#ifndef _PSORT_H_
#define _PSORT_H_

#include <iostream>
#include <vector>
#include <omp.h>

using std::vector;

namespace ParallelSort
{
    /**
     * Public wrapper for the parallel sort implementation.
     * @param array The structure to sort
     */
    template <class T>
    void psort(vector<T>* array);

    /**
     * TODO: add helper functions here.
     * Note: you can also add additional classes and/or files.
     * Make sure you follow the instructions in the Makefile.
     */
    template <class T>
    void quick_sort(vector<T> *& array,int left,int right);
    template <class T>
    void swap(vector<T> *& array, int left_end, int right_end);

}

#include "psort.cpp"
#endif
