#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct Node *next;
};

int rock(int a,int b)
{
    return a+b;
}

void printLinkList(struct node* head)
{
    struct node*temp=head;

    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
        // temp=head->next;

    }

}


int main(int argc, char const *argv[])
{
    // int,float,char,struct node

    int a1;
    int a2;
    int a3;
    a1=3;
    a2=4;
    a3=5;

    // printf("%d\n",rock(a1,a2));
    // printf("%d\n",a1);

    struct node * head;
    struct node * second;
    struct node * third;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data=8;
    head->next=second;

    second->data=12;
    second->next=third;

    third->data=45;
    third->next=NULL;

    // head->next=second;
    // second->next=third;

    // printf("%d\n",a1);

    printLinkList(head);







    




    return 0;
}
