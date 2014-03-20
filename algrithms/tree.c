#include "tree.h"

int get_tree_height(node_t* node)
{
  if(!node) return 0;
  int lnode_cnt = 0, rnode_cnt = 0;

  lnode_cnt = get_tree_height(node->left);
  rnode_cnt = get_tree_height(node->right);
  return (lnode_cnt > rnode_cnt) ? (lnode_cnt + 1):(rnode_cnt + 1);
}

void preOrderWalk(node_t* node)
{
  if(!node) return;
  printf("%d(p=%d) ", node->data, (NULL == node->parent) ? 0xffff: node->parent->data);
  preOrderWalk(node->left);
  preOrderWalk(node->right);
}

node_t* BST_insert_data(node_t* node, int data)
{
  if(!node)
  {
    node = (node_t*)malloc(sizeof(node_t));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
  }
  else
  {
    if( data < node->data ) 
    {
      node->left = BST_insert_data(node->left, data);
      node->left->parent = node;
    }
    else 
    {
      node->right = BST_insert_data(node->right, data);
      node->right->parent = node;
    }
  }
  return node;
}

node_t* BST_search_data(node_t* node, int data)
{
  if(!node) return NULL;
  if( data == node->data ) return node;
  if( data < node->data )
  {
    return BST_search_data(node->left, data);
  }
  else
  {
    return BST_search_data(node->right, data);
  }
}

node_t* BST_get_min(node_t* node)
{
  if(!node->left) return node;
  return BST_get_min(node->left);
}

node_t* BST_get_max(node_t* node)
{
  if(!node->right) return node;
  return BST_get_max(node->right);
}

void BST_swap_node_data(node_t* node_a, node_t* node_b)
{
  int tmp = node_a->data;
  node_a->data = node_b->data;
  node_b->data = tmp;
}

void BST_remove_data(node_t* rm_node)
{
  bool left_node = false;
  left_node = (rm_node->parent->left == rm_node) ? true:false;
  /* if it is a leaf node */
  if( (!rm_node->left) && (!rm_node->right) )
  {
    if(left_node) rm_node->parent->left = NULL;
    else rm_node->parent->right = NULL;
    free(rm_node);
    rm_node = NULL;
  }
  /* if it's left is empty */
  else if((!rm_node->left) && (rm_node->right))
  {
    if(left_node) rm_node->parent->left = rm_node->right;
    else rm_node->parent->right = rm_node->right;
    rm_node->right->parent = rm_node->parent;
    free(rm_node);
    rm_node = NULL;
  }
  /* if it's right is empty */
  else if((!rm_node->right) && (rm_node->left))
  {
    if(left_node) rm_node->parent->left = rm_node->left;
    else rm_node->parent->right = rm_node->left;
    rm_node->left->parent = rm_node->parent;
    free(rm_node);
    rm_node = NULL;
  }
  /* if it has both left and right sub tree */
  else
  {
    node_t* min_node = BST_get_min(rm_node->right);
    BST_swap_node_data(rm_node, min_node);
    BST_remove_data(min_node);
  }
}





