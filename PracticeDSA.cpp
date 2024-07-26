#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertattail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertatpossition(node *&head, node *&tail, int possition, int d)
{
    if (possition == 1)
    {
        insertathead(head, d);
        return;
    }

    node *ptr = new node(d);
    node *temp = head;
    int cnt = 1;
    while (cnt < possition - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    node *node1 = new node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    node *head = node1;
    node *tail = node1;

    // insertathead(head,20);
    // insertattail(tail,5);
    insertattail(tail, 20);
    insertattail(tail, 30);
    insertattail(tail, 40);
    insertatpossition(head, tail, 3, 25); 
    // insertatpossition(head, tail, 5, 90);
    print(head);

    return 0;
}
