#ifndef HTLIBS_TREE_H
#define HTLIBS_TREE_H
#include <stdio.h>
#include <stdlib.h>

#define TREE_PRINT_SPACE ( 4 )
typedef struct node_s{
  struct node_s* parent;
  struct node_s* left;
  struct node_s* right;
  int value;
}node_t;

void init_print_buf(char* buf, int size);
void print_node_to_buf(node_t* root, int x, int y, char* buf, int height);
void print_tree(node_t* root);
int get_tree_level(node_t* root);
/* for Binary Seach Tree(BST) */

void BST_insert_value(node_t** root, int value);
void BST_find_value(node_t*root);
void BST_remove_value(node_t* root, int value);
#endif
