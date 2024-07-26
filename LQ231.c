// for leaf nodes

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 

unsigned int getLeafCount(struct node* node)
{
  if(node == NULL)      
    return 0;
  if(node->left == NULL && node->right==NULL)     
    return 1;           
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);     
}
 

struct node* new(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

int main()
{
  /*create a tree*/ 
  struct node *root = new(1);
  root->left        = new(2);
  root->right       = new(3);
  root->left->left  = new(4);
  root->left->right = new(5);   
   
 
  printf("Leaf count of the tree is %d", getLeafCount(root));
   
  getchar();
  return 0;
}