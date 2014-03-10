#include "sort.h"

void swap(int *a, int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

/* for quick sort */
int partition(int* data, int low, int high)
{
  int key = *(data + high);
  int j=low;
  int i=0;
  for(i=low; i< high; i++)
  {
    if( *(data + i) <= key )
    {
       swap(data + i, data + j);
       j++;
    }
  }
  swap(data + j, data + high);
  return j;
}

void quickSort(int* data, int low, int high)
{
  int mid;
  if(low < high)
  {
    mid = partition(data, low, high);
    quickSort(data, low, mid-1);
    quickSort(data, mid+1, high);
  }  
}



