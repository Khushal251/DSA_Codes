#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node* node){

    //as linked list will end when Node is Null
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

int search(struct Node* head, int item, int index)
{
    // Base case
    if (head == NULL)
        return -1;
     
    // If data is present in current node, return true
    if (head->data == item)
        return index;
    
    // not present here will check for next position
    // in next recursive iteration
    index++;
    
    // Recur for remaining list
    return search(head->next, item, index);
}

int main()
{
    int item;
    
    //creating 4 pointers of type struct Node
    //So these can point to address of struct type variable
    struct Node* head = NULL; 
    struct Node* node2 = NULL; 
    struct Node* node3 = NULL; 
    struct Node* node4 = NULL; 

    // allocate 3 nodes in the heap 
    head =  (struct Node*)malloc(sizeof(struct Node)); 
    node2 = (struct Node*)malloc(sizeof(struct Node)); 
    node3 = (struct Node*)malloc(sizeof(struct Node)); 
    node4 = (struct Node*)malloc(sizeof(struct Node)); 

   
    head->data = 10; // data set for head node 
    head->next = node2; // next pointer assigned to address of node2 

    node2->data = 15; 
    node2->next = node3; 

    node3->data = 20;
    node3->next = node4; 

    node4->data = 25;
    node4->next = NULL;
    
    printf("Linked List: ");
    display(head); 
    
    printf("Enter element to search: ");
    scanf("%d", &item);
    
    int index = search(head, item, 0);
    
    if(index == -1)
        printf("Item not found");
    else
        printf("Item found at position: %d", index+1);

    return 0; 
}