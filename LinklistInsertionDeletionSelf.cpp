#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void linklistTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
    printf("\n");
}

struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}

struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;

    return head;
}

struct node *insertafternode(struct node *head, struct node *prenode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->next = prenode->next;
    prenode->next = ptr;
    ptr->data = data;

    return head;
}

struct node *deletionatfirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct node *deletionaftrtindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);

    return head;
}

struct node *deletionatlast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

struct node *deletionatvalue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data = value)
    {
        p->next = q->next;
        free(q);
    }

    else
    {
        printf("The element is not present in the linklist\n");

    }

    return head;
}

int main(int argc, char const *argv[])
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    linklistTraversal(head);

    // head = insertatfirst(head, 5);
    // head = insertatindex(head, 21,2);
    // head = insertatend(head, 13);
    // head = insertafternode(head, second, 57);
    // linklistTraversal(head);

    // head = deletionatfirst(head);
    // head = deletionaftrtindex(head,1);
    // head = deletionatlast(head);
    // head = deletionatvalue(head,30);
    head = deletionatvalue(head,20);
    linklistTraversal(head);

    return 0;
}
