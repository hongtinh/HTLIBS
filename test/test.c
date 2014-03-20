#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../algrithms/sort.h"
#include "../algrithms/tree.h"

#define MAX_SIZE 1000

void sort_test()
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

void tree_test()
{
  int i = 0;
  int data[10] = {4, 1, 7, 8, 3, 0, 5, 9, 2, 6};
  node_t * tree = NULL;
  for( i = 0; i < 10; ++i)
  {
    printf("%d ", data[i]);
    tree = BST_insert_data(tree, data[i]);
  }
  printf("\n");
  preOrderWalk(tree);
  printf("\n");

  node_t* node = BST_search_data( tree, 1);
  printf("found: %d ", node->data);
  printf("\n");

  printf("remove: %d ", node->data);
  BST_remove_data(node);
  printf("\n");
  preOrderWalk(tree);
  printf("\n");
}

int main()
{
  tree_test();
  return 0;
}
