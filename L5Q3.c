#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
    struct Node *ptr = head;

    do
    {
        printf("Element= %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
void enqueue(struct Node*head, int data)
{struct Node*q=head;

  
        printf("Enqueued element: %d\n", data);
    
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    // allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    // link 1st and 2nd node
    head->data = 1;
    head->next = second;
    // link 2nd and 3rd node
    second->data = 2;
    second->next = third;
    // link 3rd and 4th node
    third->data = 3;
    third->next = fourth;
    // link 4th and 5th node
    fourth->data = 4;
    fourth->next = fifth;
    // link 5thfiftho NULL
    fifth->data = 5;
    fifth->next = head;
    // display queue
    display(head);
    enqueue(head, 12);
    return 0;
}