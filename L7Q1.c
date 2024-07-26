
#include <stdio.h>
#include <stdlib.h>
 

struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};
 
struct node* minValue(struct node* node);
 
struct node* inOrderSuccessor(
    struct node* root,
    struct node* n)
{
    
    if (n->right != NULL)
        return minValue(n->right);
 
 
    struct node* p = n->parent;
    while (p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

struct node* minValue(struct node* node)
{
    struct node* current = node;
 

    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
 

struct node* new(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(
            struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
 
    return (node);
}
 

struct node* insertion(struct node* node,
                    int data)
{

    if (node == NULL)
        return (new(data));
    else {
        struct node* temp;
 

        if (data <= node->data) {
            temp = insertion(node->left, data);
            node->left = temp;
            temp->parent = node;
        }
        else {
            temp = insertion(node->right, data);
            node->right = temp;
            temp->parent = node;
        }
 
        return node;
    }
}

int main()
{
    struct node *root = NULL, *temp, *succ, *min;
 

    root = insertion(root, 20);
    root = insertion(root, 8);
    root = insertion(root, 22);
    root = insertion(root, 4);
    root = insertion(root, 12);
    root = insertion(root, 10);
    root = insertion(root, 14);
    temp = root->left->right->right;
 
    succ = inOrderSuccessor(root, temp);
    if (succ != NULL)
        printf(
            "\n Inorder Successor of %d is %d ",
            temp->data, succ->data);
    else
        printf("\n Inorder Successor doesn't exit");
 
    getchar();
    return 0;
}