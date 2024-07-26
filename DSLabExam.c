#include<stdio.h>
#include<stdlib.h>
 
struct Node
{

    int data;
    struct Node * next;
};
 
struct Node* top = NULL;
 

 
int Empty(struct Node* top)
{
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 


int Full(struct Node* top)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* insertion(struct Node* top, int x)
{
    if(Full(top)){
        printf("Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}


 
int deletion(struct Node* ab)
{
    if(Empty(ab)){
        printf("Underflow\n");
    }
    else{
        struct Node* n = ab;
        top = (ab)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}

void Display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("the values of Element is : %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int main(){
    top = insertion(top, 12);
    top = insertion(top, 5);
    top = insertion(top, 16);
    Display(top);
 
    int element = deletion(top); 
    printf("deleting element is %d\n", element);
    Display(top);
    return 0;
}