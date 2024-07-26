#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct node *next;
};

// void linklist(struct Node *ptr)
// {

//     // ptr=(struct node*)malloc(sizeof(struct node));

//     while (ptr != NULL)
//     {
//         printf("element: %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

void linkprint(struct Node *head)
{
    struct Node *ptr=head;
    printf("Element is %d\n", ptr->data);
    ptr=ptr->next;
    while(ptr!=head)
    {
         printf("Element is %d\n", ptr->data);
         ptr=ptr->next;
    }
    
}

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

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 14;
    fourth->next = head;

    // linklist(head);
    // printf("\n");

    printf("\n");
   linkprint(head);



    return 0;
}
