#include <string.h>
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
  for(i=low; i< high; ++i)
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



/* for merge sort */
void merge(int *data, int low, int mid, int high)
{
  int i, j, k;
  int *pTmp = (int*)malloc( sizeof(int) * (high - low + 1) );

  for( i = low, j = mid + 1, k = 0; i <= mid; ++k){
    if( j > high) break;
    if( *(data + i) <= *(data + j) ){
      *(pTmp + k) = *(data + i);
      i++;
    }else{
      *(pTmp + k) = *(data + j);
      j++;
    }
  }

  if( i <= mid ){
    memcpy( pTmp + k, data + i, sizeof(int)*(mid-i + 1));
  }
  if( j <= high){
    memcpy( pTmp + k, data + j, sizeof(int)*(high-j +1));
  }
  memcpy(data + low, pTmp, sizeof(int)*(high - low +1));
  if(pTmp) free(pTmp);
}


void mergeSort(int *data, int low, int high)
{
  if( low < high){
    int mid = (low + high)/2;
    mergeSort(data, low, mid);
    mergeSort(data, mid + 1, high);
    merge(data, low, mid, high);
  }
}


/* for heap sort */
void maxHeapify(int *data, int i, int size)
{
  int ln, rn, bign = i;
  ln = 2*i + 1;
  rn = 2*i + 2;
  if( ln < size ) bign = (*(data + i) > *(data + ln)) ? i:ln;
  if( rn < size ) bign = (*(data + bign) > *(data + rn)) ? bign:rn;
  if(bign != i){
    swap(data + bign, data + i);
    maxHeapify( data, bign, size);
  }
}

void buildMaxHeap(int *data, int size)
{
  int i;
  for(i = size/2; i >= 0; --i){
    maxHeapify(data, i, size);
  }
}

void heapSort(int *data, int size)
{
  int i;
  buildMaxHeap(data, size);
  for(i = size - 1; i >= 0; --i){
    swap(data, data + i);
    buildMaxHeap(data, i);
  }
}
