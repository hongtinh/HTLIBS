#ifndef HTLIBS_SORT_H
#define HTLIBS_SORT_H

#include <stdlib.h>


/* quick sort */
void quickSort(int* data, int low, int high);
/*merge sort */
void mergeSort(int *data, int low, int high);
/*heap sort */
void heapSort(int *data, int size);


#endif

