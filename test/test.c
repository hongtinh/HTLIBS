#include <stdio.h>
#include <stdlib.h>
#include "../algrithms/sort.h"

#define MAX_SIZE 1000

int main()
{
  int i= 0;
  int data[MAX_SIZE];
  srand((unsigned)time(NULL));
  for(i=0; i< MAX_SIZE; i++) 
  {
    data[i] = rand()%MAX_SIZE;
    printf("%d ", data[i]);
  }
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");

  //mergeSort(data, 0, MAX_SIZE -1 );
  heapSort(data, MAX_SIZE);
  for(i=0; i< MAX_SIZE; i++) 
  {
    printf("%d ", data[i]);
  }
  printf("\n");


}
