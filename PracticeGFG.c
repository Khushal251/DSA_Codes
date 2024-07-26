#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

// struct node createnode(struct node *head, int data)
// {

// }

void Traversal(struct node *ptr)
{
    printf("The Linkedlist is \n");
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
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

struct node *insertatEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;

    return head;
}

struct node *insertafteranode(struct node *head, struct node *prev, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->next = prev->next;
    prev->next = ptr;
    ptr->data = data;

    return head;
}

struct node *deletefromfirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct node *deleteformindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

struct node *deletefromvalue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data = value)
        p->next = q->next;
    free(q);

    return head;
}

struct node *deletefromlast(struct node *head)
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

struct node *Circulartraversal(struct node *head)
{
    struct node *ptr = head;
    printf("The LinkedList is \n");
    printf("Element : %d\n", ptr->data);
    ptr = ptr->next;
    while (ptr != head)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    return head;
}

struct node *insertatfirstinCircularLinklist(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    head = ptr;
    return head;
}

// struct node * insertnext(struct node *head, int data)
// {
//     struct node *ptr = (struct node *)malloc(sizeof(struct node));

// }

int getNthFromLast(struct node *head, int n)
{
    int count = 1;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        count++;
    }
    if (n > count)
    {
        return -1;
    }
    p = head;
    int i = 0;
    int x = count - n;
    while (i != x)
    {

        p = p->next;
        i++;
    }
    return p->data;
    // return count;
}

int getMiddle(struct node *head)
{
    int count = 1;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        count++;
    }
    int l;
    if (count % 2 != 0)
    {
        l = (count + 1) / 2;
    }
    else if (count % 2 == 0)
    {
        l = (count + 2) / 2;
    }

    p = head;
    int i = 0;

    while (i != l - 1)
    {

        p = p->next;
        i++;
    }
    return p->data;
}

struct node *reverseList(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int count = 1;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        count++;
    }
    // int a[count];
    p = head;
    for (int i = count - 1; i >= 0; i--)
    {
        a[i] = p->data;
        p = p->next;
    }

    ptr->data = a[0];
    ptr->next = NULL;

    for (int i = 1; i < count; i++)
    {

        ptr = insertatEnd(ptr, a[i]);

        
    }

    return ptr;
}

int main(int argc, char const *argv[])
{
    struct node *head;
    // struct node *second;
    // struct node *third;
    // struct node *fourth;
    // struct node *fifth;
    // struct node *sixth;
    // struct node *seventh;
    // struct node *eight;

    head = (struct node *)malloc(sizeof(struct node));
    // second = (struct node *)malloc(sizeof(struct node));
    // third = (struct node *)malloc(sizeof(struct node));
    // fourth = (struct node *)malloc(sizeof(struct node));
    // fifth = (struct node *)malloc(sizeof(struct node));
    // sixth = (struct node *)malloc(sizeof(struct node));
    // seventh = (struct node *)malloc(sizeof(struct node));
    // eight = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = NULL;

    // second->data = 2;
    // second->next = third;

    // third->data = 3;
    // third->next = fourth;

    // fourth->data = 4;
    // fourth->next = fifth;

    // fifth->data = 5;
    // fifth->next = sixth;

    // sixth->data = 6;
    // sixth->next = seventh;

    // seventh->data = 7;
    // seventh->next = eight;

    // eight->data = 8;
    // eight->next = NULL;

    // Traversal(head);
    // printf("%d\n", getNthFromLast(head, 2));
    // head=insertatfirst(head,1);
    // head=insertatindex(head,67,3);
    // head=insertatEnd(head,83);
    // head=insertafteranode(head,second,67);
    // head=deletefromfirst(head);
    // head=deleteformindex(head,2);
    // head=deletefromlast(head);
    // head=deletefromvalue(head,33);
    // Traversal(head);

    head = insertatEnd(head, 2);
    head = insertatEnd(head, 3);
    head = insertatEnd(head, 4);
    head = insertatEnd(head, 5);
    // head = insertatEnd(head, 6);
    struct node *abc = (struct node *)malloc(sizeof(struct node));
    abc = reverseList(head);
    // Traversal(head);
    // printf("%d\n", getMiddle(head));

    Traversal(abc);

    return 0;
}
