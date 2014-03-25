#ifndef HTLIBS_TREE_H
#define HTLIBS_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node_s{
  struct node_s* parent;
  struct node_s* left;
  struct node_s* right;
  int data;
}node_t;

/* Tree common functions */
int get_tree_height(node_t* node);
void pre_order_walk(node_t* node);

/* for BST(Binary Seach Tree)) */
node_t* BST_insert_data(node_t* node, int data);
node_t* BST_search_data(node_t* node, int data);
void BST_remove_data(node_t* node);
node_t* BST_get_min(node_t* node);
node_t* BST_get_max(node_t* node);
void BST_swap_node_data(node_t* node_a, node_t* node_b);
#endif
