#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct node *next;
};

void linklist(struct Node *ptr)
{

    // ptr=(struct node*)malloc(sizeof(struct node));

    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertatfirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
};

struct Node *insertatindex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;
};

struct Node *insertatEND(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while (p->next!=NULL)
    {
        p=p->next;
        
    }
    ptr->data=data;
    ptr->next=NULL;
    p->next=ptr;

    return head;
};

struct Node *insertafterNode(struct Node *head,struct Node *prevnode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;

    return head;
};

struct Node *deletionatbegining(struct Node *head)
{
    struct Node *ptr = head;
    
    head=head->next;
    free(ptr);

    return head;

};

struct Node * deletionfromindex(struct Node * head, int index)
{
    struct Node *p=head;
    struct Node *q=head->next;
    int i=0;

    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;

};

struct Node * deletionfromlast(struct Node * head)
{
    struct Node *p=head;
    struct Node *q=head->next;
    

    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
        
    }
    p->next=NULL;
    free(q);
    return head;

};

struct Node * deletionatindex(struct Node * head,int value)
{
    struct Node *p=head;
    struct Node *q=head->next;
    

    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
        
    }
    if(q->data==value)
    {
    p->next=q->next;
    free(q);
    return head;
    }

};
int main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct node *)malloc(sizeof(struct Node));
    second = (struct node *)malloc(sizeof(struct Node));
    third = (struct node *)malloc(sizeof(struct Node));
    fourth = (struct node *)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = second;

    second->data = 34;
    second->next = third;

    third->data = 47;
    third->next = fourth;

    fourth->data = 67;
    fourth->next = NULL;

    linklist(head);
    printf("\n");
    // head=insertatfirst(head, 90);
    // head=insertatindex(head,90,2);
    // head=insertatEND(head,90);
    // head=insertafterNode(head,second,90);
    // head =deletionatbegining(head);
    // head=deletionfromindex(head,2);
    // head=deletionfromlast(head);
    head=deletionatindex(head,34);
    printf("\n");
    linklist(head);



    return 0;
}
