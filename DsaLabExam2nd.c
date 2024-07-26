#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int queue_array[5];
int rear = -1;
int front = -1;
struct Node
{
    int roll, marks;
    struct Node *next;
};
void insert(struct Node *node)
{
    if (rear == 4)
    {
        printf("Queue Overflow \n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        while (node != NULL)
        {
            if (node->marks < 40)
            {
                if (rear == 4)
                {
                    printf("Queue Overflow \n");
                    return;
                }
                rear = rear + 1;
                queue_array[rear] = node->roll;
            }
            node = node->next;
        }
    }
}

void append(struct Node **head_ref, int r, int m)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *head_ref;
    new_node->roll = r;
    new_node->marks = m;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Students with Marks Below 40 are : \n");
        for (i = front; i <= rear; i++)
            printf("Roll No. = %d \n", queue_array[i]);
        printf("\n");
    }
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("Roll. No. = %d with Marks = %d \n", node->roll, node->marks);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;
    append(&head, 1, 43);
    append(&head, 2, 39);
    append(&head, 3, 90);
    append(&head, 4, 25);
    append(&head, 5, 89);
    insert(head);
    printf("\nResult is:\n");
    printList(head);
    display();
    return 0;
}
