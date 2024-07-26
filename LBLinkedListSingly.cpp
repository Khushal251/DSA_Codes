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
node *reverse(node *&head)
{
    node *curr = head;
    node *pre = NULL;
    node *forward;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
    }
    head = pre;
}

int getlength(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return ((count / 2) + 1);
    // return count;
}

node *middlenode(node *head)
{
    node *temp = head;
    int n = getlength(head);
    int i = 1;
    while (i != n)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}

bool detectloop(node *head)
{
    node *temp = head;
    map<node *, bool> m;

    while (temp != NULL)
    {
        if (m[temp] == true)
        {
            return true;
        }
        m[temp] = true;
        temp = temp->next;
    }
    return false;
}

node *detectloopFloyd(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *fast = head;
    node *slow = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;
        if (slow == fast)
        {
            cout << "Loop present at " << slow->data << endl;
            return slow;
        }
    }
    cout << "Loop not present " << endl;

    return NULL;
}

node *getstartingnode(node *head)
{
    // A+B=k*C
    // explained in video
    if (head == NULL)
    {
        return NULL;
    }
    node *intersection = detectloopFloyd(head);
    node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removerepeatedloop(node *head)
{
    if (head == NULL)
        return;

    node *startofloop = getstartingnode(head);
    node *temp = startofloop;

    while (temp->next != startofloop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

node *kreverse(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    // reverse first k nodes
    node *next = NULL;
    node *curr = head;
    node *pre = NULL;
    int count = 0;
    node *temp = head;
    int c = 1;

    while (temp->next != NULL)
    {
        temp = temp->next;
        c++;
    }
    if (c < k)
    {
        return curr;
    }

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        count++;
    }

    // Recursion
    if (next != NULL)
    {
        head->next = kreverse(next, k);
    }

    // return head of reverse list
    return pre;
}

node *DeleteDublicateSortedLL(node *head)
{
    if (head == NULL)
        return head;

    node *curr = head;
    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            node *pop = curr->next->next;
            node *temp = curr->next;
            // curr = curr->next->next;
            delete temp;
            curr->next = pop;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

node *sort(node *head)
{
    vector<int> v;
    node *temp = head;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(), v.end());
    node *pop = head;
    int i = 0;
    while (pop != NULL)
    {
        pop->data = v[i];
        i++;
        pop = pop->next;
    }

    return head;
}

node *merge(node *head1, node *head2)
{

    if (head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }

    node *curr1 = head1;
    node *next1 = curr1->next;
    node *curr2 = head2;
    node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return head1;
            }
        }
    }
}
node *mergeCheck(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data <= head2->data)
    {
        return merge(head1, head2);
    }
    else
    {
        return merge(head2, head1);
    }
}

void solve(node *first, node *second)
{

    node *curr1 = first;
    node *next1 = curr1->next;

    node *curr2 = second;
    node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {

        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {

            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
        }
    }
}

node *sortTwoLists(node *first, node *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    if (first->data <= second->data)
    {
        solve(first, second);
    }
    else
    {
        solve(second, first);
    }
}

node *middlenodeFloydMethod(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *reverseForPelendrome(node *head)
{
    node *pre = NULL;
    node *curr = head;
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

bool checkPelendrome(node *head, node *mid)
{
    node *curr = head;
    node *forw = mid;

    while (forw != NULL)
    {
        if (curr->data != forw->data)
        {
            return false;
        }
        curr = curr->next;
        forw = forw->next;
    }
    return true;
}

bool isPelendrome(node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    node *middle = middlenodeFloydMethod(head);

    middle->next = reverseForPelendrome(middle->next);

    if (checkPelendrome(head, middle->next))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void insertAtTail(struct node *&head, struct node *&tail, int data)
{

    node *temp = new node(data);
    // empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
node *reversetoadd(node *head)
{

    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node *add(node *first, node *second)
{
    int carry = 0;

    node *ansHead = NULL;
    node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {

        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // create node and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}

node *addTwoNumbers(node *first, node *second)
{
    // step 1 -  reverse input LL
    first = reversetoadd(first);
    second = reversetoadd(second);

    // step2 - add 2 LL
    node *ans = add(first, second);

    // step 3
    ans = reversetoadd(ans);

    return ans;
}

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

node* sortList(node* head){
    // Write your code here.
    node* temp=head;

    while(temp->next!=NULL)
    {
        cout<<temp->data;
        if(temp->next->data<temp->data)
        {
            int x=temp->data;
            temp->data=temp->next->data;
            temp->next->data=x;
            cout<<"*";
        }
        else
        temp=temp->next;
        cout<<" ";
    }
    cout<<endl;
    return head;
}

int32_t main()
{
    node *node1 = new node(10);
    node *head = new node(1);
    node *tail = head;
    // insertatfirst(head, 20);
    // insertatfirst(head, 30);
    // insertatend(head, tail, 40);
    // insertatpossition(head, tail, 5, 25);
    // traversal(head);
    // cout<<"head : "<<head->data<<endl;
    // cout<<"tail : "<<tail->data<<endl;

    insertatend(head, tail, 9);
    insertatend(head, tail, 3);
    insertatend(head, tail, 8);
    insertatend(head, tail, 4);
    // insertatend(head, tail, 60);
    // insertatend(head, tail, 70);
    // insertatend(head, tail, 20);
    traversal(head);
    // deleteatpossition(head, tail, 1);
    // deleteatpossition(head, tail, 5);
    // cout << "head : " << head->data << endl;
    // cout << "tail : " << tail->data << endl;
    // reverse(head);
    // traversal(head);
    // tail->next = head->next->next;
    // detectloop(head);
    // cout<<detectloop(head)<<endl;
    // if(detectloop(head))
    // {
    //     cout<<"yes"<<endl;
    // }
    // detectloopFloyd(head);
    // node *ans = getstartingnode(head);
    // cout << "begining of loop is " << ans->data << endl;
    // removerepeatedloop(head);
    // detectloopFloyd(head);

    // head = DeleteDublicateSortedLL(head);
    // head = sort(head);
    // node *head1 = new node(1);
    // node *tail1 = head1;
    // insertatend(head1, tail1, 2);
    // insertatend(head1, tail1, 4);
    // insertatend(head, tail, 20);

    // node *head2 = new node(1);
    // node *tail2 = head2;
    // insertatend(head2, tail2, 3);
    // insertatend(head2, tail2, 4);

    // traversal(head1);
    // traversal(head2);

    // node*head=mergeCheck(head1,head2);
    // node *ans = sortTwoLists(head1, head2);
    // traversal(ans);
    // cout << middlenodeFloydMethod(head)->data << endl;
    head=sortList(head);
    traversal(head);


    // head=reverseForPelendrome(head);
    // cout << isPelendrome(head) << endl;
    // traversal(head);

    return 0;
}
