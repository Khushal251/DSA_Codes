#include <bits/stdc++.h>
using namespace std;
#define int long long int

class node
{
public:
    int data;
    node *pre;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }

    // Distructor
    ~node()
    {
        int value=this->data;
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"memory free from node with data "<<value<<endl;
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

void getlength(node *&head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "The length is : " << count << endl;
}

void insertathead(node *&head, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
}

void insertattail(node *&head, node *&tail, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->pre = tail;
        tail = temp;
    }
}

void insertatpossition(node *&head, node *&tail, int p, int d)
{
    node *newnode = new node(d);
    if (p == 1)
    {
        insertathead(head, d);
        return;
    }
    node *temp = head;
    int i = 1;
    while (i < p - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        insertattail(head, tail, d);
        return;
    }

    node *temp2 = temp->next;
    newnode->next = temp->next;
    temp2->pre = newnode;
    temp->next = newnode;
    newnode->pre = temp;

    // newnode->next = temp->next;
    // temp->next->pre = newnode;
    // temp->next = newnode;
    // newnode->pre = temp;
}

void deletion(node*&head,node*&tail,int p)
{
    if(p==1)
    {
        node*temp=head;
        temp->next->pre=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        node*curr=head;
        node*prev=NULL;
        int i=1;
        while(i<p)
        {
            prev=curr;
            curr=curr->next;;
            i++;
        }
        if(curr->next==NULL)
        {
            tail=curr->pre;
            prev->next=NULL;
            curr->pre=NULL;
            delete curr;
            return;
        }

        prev->next=curr->next;
        curr->next->pre=prev;
        curr->pre=NULL;
        curr->next=NULL;
        delete curr;
    } 
}

void reverse(node* head)
{
    node* curr=head;
    node* temp=NULL;

    while(curr!=NULL)
    {
        temp=curr->pre;
        curr->pre=curr->next;
        curr->next=temp;
        curr=curr->pre;
    }

    if(temp!=NULL)
    head=temp->pre;
}

int32_t main()
{
    node *head = new node(10);
    node *tail = head;
    // traversal(head);
    // getlength(head);
    // insertathead(head,5);
    // traversal(head);
    // insertattail(head,tail,20);
    insertattail(head, tail, 20);
    insertattail(head, tail, 30);
    insertattail(head, tail, 40);
    insertattail(head, tail, 50);
    traversal(head);
    insertatpossition(head, tail, 1, 5);
    traversal(head);
    insertatpossition(head, tail, 4, 25);
    traversal(head);
    insertatpossition(head, tail, 8, 100);
    // cout << "head : " << head->data << endl;
    // cout << "tail : " << tail->data << endl;
    traversal(head);
    deletion(head,tail,8);
    traversal(head);
    
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    return 0;
}
