#include <stdlib.h>
#include <string.h>
#include "sort.h"
static void swap(int *a, int *b);
static int partition(int *a, int begin, int end);
static void merge(int *data, int low, int mid, int high);
static void buildMaxHeap(int *data, int size);
static void maxHeapify(int *data, int i, int size);


static void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

static int partition(int *a, int begin, int end)
{
	int i = begin;
	int j = end;
	int key = begin;

	if (i == j) return i;

	while (i < j) {

		if (j > key) {
			if (a[j] < a[key]) {
				swap(a + key, a + j);
				key = j;
			} else {
				j--;
				if (i == j) break;
			}
		}

		if (i < key) {
			if (a[i] > a[key]) {
				swap(a + i, a + key);
				key = i;	
			} else {
				i++;
				if (i == j) break;
			}
		}

	}
	return i;
}

void quickSort(int* data, int low, int high)
{

	int mid;
	if (low < high) {
		mid = partition(data, low, high);
		quickSort(data, low, mid);
		quickSort(data, mid + 1, high);
	}  

}


static void merge(int *a, int begin, int mid, int end)
{
	int i,j,k;
	int *buf = (int*)malloc(sizeof(int) * (end - begin + 1));

	i = begin; 
	j = mid + 1; 
	k = 0; 

	while (i <= mid || j <= end) {
		if (a[i] > a[j]) {
			buf[k] = a[j];
			k++;

			if (j == end) {
				memcpy(buf + k, a + i, sizeof(int) * (mid - i + 1));
				memcpy(a + begin, buf, sizeof(int) * (end - begin + 1));
				return;
			}

			j++;
		} else {
			buf[k] = a[i];
			k++;

			if (i == mid) {
				memcpy(buf + k, a + j, sizeof(int) * (end - j + 1));
				memcpy(a + begin, buf, sizeof(int) * (end - begin + 1));
				return;
			}

			i++;
		}
	}

	free(buf);
}


void mergeSort(int *data, int low, int high)
{
	if (low < high) {
		int mid = (low + high)/2;
		mergeSort(data, low, mid);
		mergeSort(data, mid + 1, high);
		merge(data, low, mid, high);
	}
}


static void maxHeapify(int *data, int i, int size)
{
	int ln, rn, bign = i;
	ln = 2*i + 1;
	rn = 2*i + 2;
	if (ln < size) bign = (*(data + i) > *(data + ln)) ? i:ln;
	if (rn < size) bign = (*(data + bign) > *(data + rn)) ? bign:rn;
	if (bign != i) {
		swap(data + bign, data + i);
		maxHeapify( data, bign, size);
	}
}

static void buildMaxHeap(int *data, int size)
{
	int i;
	for (i = size/2; i >= 0; --i) {
		maxHeapify(data, i, size);
	}
}

void heapSort(int *data, int size)
{
	int i;
	buildMaxHeap(data, size);
	for (i = size - 1; i >= 0; --i) {
		swap(data, data + i);
		buildMaxHeap(data, i);
	}
}
