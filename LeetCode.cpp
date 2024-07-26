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

void traversal(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertatfirst(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertatend(node *&head, node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertatpossition(node *&head, node *&tail, int p, int d)
{
    node *temp = head;
    node *nodetoinsert = new node(d);
    if (p == 1)
    {
        insertatfirst(head, d);
        return;
    }

    int i = 1;
    while (i < p - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        insertatend(head, tail, d);
        return;
    }
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void deleteatpossition(node *&head, node *&tail, int p)
{
    if (p == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        node *curr = head;
        node *pre = NULL;
        int i = 1;
        while (i < p)
        {
            pre = curr;
            curr = curr->next;
            i++;
        }
        if (curr->next == NULL)
        {
            tail = pre;
        }
        pre->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

node *RemoveElement(node *head, int val)
{
    while (head->data == val)
    {
        if (head->data == val)
        {
            node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    node *pre = NULL;
    node *curr = head;
    node *forw;

    // pre->next=curr;
    while (curr != NULL)
    {
        if (head == NULL)
            return head;

        // while(head->data!=val)
        // {
        //     node*temp=head;
        //     head=head->next;
        //     temp->next==NULL;
        //     delete temp;
        // }

        if (curr->data == val)
        {

            forw = curr->next;
            node *temp = curr;
            pre->next = curr->next;
            curr = forw;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            pre = curr;
            curr = curr->next;
        }
    }
    return head;
}

// node * RemoveElement(node*head,int val)
// {
//     if(head==NULL)
//     return head;
//     // if(head->next==NULL)
//     node * temp=head;
//     while(temp->next!=NULL)
//     {
//         if(temp->next->data==val)
//         {
//             node*ans=temp->next;
//             temp=temp->next->next;
//             ans->next=NULL;
//             delete ans;
//         }
//         else
//         temp=temp->next;
//     }
//     return head;

// }
node *deleteKey(node *head, int x)
{
    // In Linked List is empty Just return it
    if (!head)
        return head;
    // Until the head data is equal to the key move the head
    // pointer
    while (head && head->data == x)
    {
        head = head->next;
    }
    node *curr = head, *prev = NULL;

    while (curr != NULL)
    {
        if (curr->data == x)
        {
            prev->next = curr->next;
        }
        else
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

node *reverseofLL(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *curr = head;
    node *pre = NULL;
    node *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forw;
    }
    return pre;
}

node *removeNthFromEnd(node *head, int n)
{

    head = reverseofLL(head);

    if (n == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *pre = NULL;
        int i = 0;
        while (i < n - 1)
        {
            pre = curr;
            curr = curr->next;
            i++;
        }
        pre->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    head = reverseofLL(head);
    return head;
}

node *swapPairs(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *pre = head;
    // node *curr=head->next;
    // int count=0;
    // while (pre->next != NULL)
    // {
    //     if(count!=0)
    //     {
    //         curr=curr->next;

    //     }
    //     pre->next = curr->next;
    //     curr->next = pre;
    //     head=curr;
    //     pre = pre->next;
    //     count++;
    // }
    while (pre != NULL && pre->next != NULL)
    {
        int count = pre->data;
        pre->data = pre->next->data;
        pre->next->data = count;
        pre = pre->next->next;
    }
    return head;
}

// node*rotate(node*head,int k)
// {
//     if(head==NULL)
//     {
//         return NULL;
//     }
//     //Set tail pointer and count number of nodes;
//     node*tail=head;
//     node*curr=head;
//     int size=1;
//     while(tail->next!=NULL)
//     {
//         tail=tail->next;
//         size++;
//     }

//     int x=size-k;
//     int i=0;
//     while(i<x-1)
//     {
//         curr=curr->next;
//         i++;

//     }

//     tail->next=head;
//     head=curr->next;
//     curr->next=NULL;

//     return head;

// }

node *rotate(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    // Set tail pointer and count number of nodes;
    node *tail = head;
    node *curr = head;
    int size = 1;
    while (tail->next != NULL)
    {
        tail = tail->next;
        size++;
    }

    // int x = size - k;
    // int i = 0;

    // while (i < x - 1)
    // {
    //     curr = curr->next;
    //     i++;
    // }

    // int i=k%size;
    // while(i!=0)
    // {
    //     curr = curr->next;
    //     i--;

    // }
    k = k % size;
    int x = size - k;
    int i = 0;

    while (i < x - 1)
    {
        curr = curr->next;
        i++;
    }

    tail->next = head;
    head = curr->next;
    curr->next = NULL;

    return head;
}
int getsize(node*head)
{
    int i=0;
    node*temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return i;

}

node* deleteatposs(node *head)
{
    int p=(getsize(head))/2+1;
    if (p == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        node *curr = head;
        node *pre = NULL;
        int i = 1;
        while (i < p)
        {
            pre = curr;
            curr = curr->next;
            i++;
        }

        pre->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    return head;
}

node *getmiddleFloydques(node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL )
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast==NULL)
    {
        return slow;
    }
    if(fast->next==NULL)
    {
        return slow->next;
    }
    // return slow;
}
void deleteatpossition(node *&head, int p)
{
    if (p == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        node *curr = head;
        node *pre = NULL;
        int i = 1;
        while (i < p)
        {
            pre = curr;
            curr = curr->next;
            i++;
        }

        pre->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

node * deletedublicatesorted(node * head)
{
    if(head==NULL)
    {
        return head;
    }
    node * curr=head;
    node * pre=NULL;
    bool a=false;
    int i=1;
    while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            curr->next=curr->next->next;
            a=true;
        }
        else
        {
            if(a==true)
            {
                curr=curr->next;
                deleteatpossition(head,i);
                i++;
                a=false;


            }
            else
            {
            curr=curr->next;
            i++;

            }
        }

    }
    return head;

}

int32_t main()
{

    node *head = new node(1);
    node *tail = head;
    insertatend(head, tail, 1);
    insertatend(head, tail, 1);
    insertatend(head, tail, 2);
    insertatend(head, tail, 3);
    // insertatend(head, tail, 4);
    // insertatend(head, tail, 5);
    traversal(head);
    // head = RemoveElement(head, 1);
    // head = deleteKey(head, 1);
    // head=reverseofLL(head);
    // head=(removeNthFromEnd(head,7));
    // head = swapPairs(head);
    // node*last=rotate(head,2);
    // head = rotate(head, 6);
    // cout<<last->data<<endl;
    // node *temp = getmiddleFloydques(head);
    // cout << temp->data << endl;
    // cout<<getmiddleFloydques(head)->data<<endl;
    // cout<<getsize(head)<<endl;
    // head=deleteatpossition(head);
    head=deletedublicatesorted(head);
    traversal(head);
    // cout<<6%5<<endl;

    return 0;
}
