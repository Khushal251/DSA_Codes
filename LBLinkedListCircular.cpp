#include <bits/stdc++.h>
using namespace std;
#define int long long int

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Distructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free from node with data " << value << endl;
    }
};

void insertion(node *&tail, int element, int d)
{
    // Empty List
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        // Non Empty Element
        // assuming that the element is present in the list

        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        node *newnode = new node(d);
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void traversal(node *&tail)
{
    if (tail == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        node *temp = tail;
        cout << tail->data << " ";
        tail = tail->next;
        while (tail != temp)
        {
            cout << tail->data << " ";
            tail = tail->next;
        }
        cout << endl;
    }
}

void deletion(node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "The list is already empty" << endl;
    }
    else
    {
        node *prev = tail;
        node *curr = prev->next;
        if (curr == prev)
        {
            tail = NULL;
            return;
        }
        while (curr->data != value)
        {
            curr = curr->next;
            prev = prev->next;
        }
        // if (curr == tail)
        // {
        //     tail = curr->next;
        // }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int32_t main()
{
    node *tail = NULL;
    // insertion(tail, 5, 3);
    // traversal(tail);
    // insertion(tail, 3, 4);
    // traversal(tail);
    // insertion(tail, 4, 5);
    // traversal(tail);
    insertion(tail, 5, 6);
    traversal(tail);
    insertion(tail, 6, 7);
    traversal(tail);
    // cout<<tail->next->data<<endl;
    deletion(tail, 7);
    traversal(tail);
    deletion(tail, 6);
    traversal(tail);
    deletion(tail, 6);
    traversal(tail);
    // cout<<tail->data<<endl;

    return 0;
}
