#include "tree.h"

int get_tree_level(node_t* root)
{
  if(!root) return 0;
  int lnode_cnt = 0, rnode_cnt = 0;

  lnode_cnt = get_tree_level(root->left);
  rnode_cnt = get_tree_level(root->right);
  return (lnode_cnt > rnode_cnt) ? (lnode_cnt + 1):(rnode_cnt + 1);
}


/* for print tree */
void init_print_buf(char* buf, int size)
{
  memset(buf, ' ', size* sizeof(char));
}
void print_node_to_buf(node_t* root, int x, int y, char* buf, int height)
{
  if(!root) return;
  sprintf( buf + (y*height*2 + x)*TREE_PRINT_SPACE , "%d", root->value );
  sprintf( buf + (y*height + x - 1 )*TREE_PRINT_SPACE, "%s", "/");
  sprintf( buf + (y*height + x + 1 )*TREE_PRINT_SPACE, "%s", "\\");
  print_node_to_buf(root->left, x - 1 , y + 2, buf, height);
  print_node_to_buf(root->right, x + 1 , y + 2, buf, height);
}

void print_tree(node_t* root)
{
  if(!root) {
    printf("tree is empty \n");
    return;
  }
  int root_x, root_y;
  int i,j;
  int height = get_tree_level(root);
  printf("tree height is %d \n", height);
  char* print_buf = (char*)malloc(sizeof(char) * (height)*(height*2));
  init_print_buf(print_buf, height*height*2);
  root_x = height; 
  root_y = 0;
  print_node_to_buf(root, root_x, root_y, print_buf, height);
  for( i = 0; i < height*height*2*TREE_PRINT_SPACE; ++i){
    printf("%s", print_buf + i);
    if( 0 == i%height ) printf("\n");
  }
}

void BST_insert_value(node_t** root, int value)
{
  if(!(*root)){
    (*root) = (node_t*)malloc(sizeof(node_t));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->parent = NULL;
    (*root)->value = value;
  }else{
    if( value < (*root)->value ) BST_insert_value(&((*root)->left), value);
    else BST_insert_value(&((*root)->right), value);
  }
}

void preOrderWalk(node_t* root)
{
  if(!root) return;
  printf("%d ", root->value);
  preOrderWalk(root->left);
  preOrderWalk(root->right);
}

#define MAX_SIZE 16 

int main()
{
  int i= 0;
  int data[MAX_SIZE];
  //node_t* root = (node_t*)malloc(sizeof(node_t));
  node_t* root = NULL;
  srand((unsigned)time(NULL));
  for(i=0; i< MAX_SIZE; i++) 
  {
    data[i] = rand()%MAX_SIZE;
    BST_insert_value(&root, data[i]);
    printf("%d ", data[i]);
  }
  printf("\n");
  preOrderWalk(root);
  //print_tree(root);
}
