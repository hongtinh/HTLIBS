#ifndef HTLIBS_SORT_H
#define HTLIBS_SORT_H

#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b);

/* for quick sort */
int partition(int* data, int low, int high);
void quickSort(int* data, int low, int high);


#endif

