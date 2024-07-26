#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// create tree
struct node *create()
{
    int x;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data (enter -1 for leaf node): ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    new_node->data = x;
    printf("Enter left child of %d:\t", x);
    new_node->left = create();
    printf("Enter right child of %d:\t", x);
    new_node->right = create();
    return new_node;
}
// calculate height of tree
// height=max number of nodes from root to leaf
int height(struct node *root)
{
    if (root == 0)
    {
        return 0;
    }
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
// count node
int countNode(struct node *root)
{
    if (root == 0)
    {
        return 0;
    }
    else
    {
        return (1 + countNode(root->left) + countNode(root->right));
    }
}
// count right nodes
int countRightNode(struct node *root)
{
    if (root == 0)
    {
        return 0;
    }
    else
    {
        return (countNode(root->right));
    }
}
// count leaf nodes
int countLeafNode(struct node *root)
{
    if (root)
    {
        if (root->left == 0 && root->right == 0)
        {
            count++;
        }
        else
        {
            if (root->left)
            {
                countLeafNode(root->left);
            }
            if (root->right)
            {
                countLeafNode(root->right);
            }
        }
    }
    return count;
}
// lowest element in BST
int lowestElement(struct node *root){
    if(root==0){
        return 0;
    }
while(root->left!=0){
    root=root->left;
}
return root->data;
}

    int main()
{
    struct node *root;
    root = 0;
    root = create();
    int h = height(root);
    printf("HEIGHT OF TREE IS: %d\n", h);
    int n = countNode(root);
    printf("NUMBER OF NODES OF TREE ARE: %d\n", n);
    int rn = countRightNode(root);
    printf("NUMBER OF RIGHT NODES OF TREE ARE: %d\n", rn);
    int count = 0;
    int ln = countLeafNode(root);
    printf("NUMBER OF LEAF NODES OF TREE ARE: %d\n", ln);
    int le = lowestElement(root);
    printf("Lowest element of BST is: %d\n", le);

    return 0;
}
