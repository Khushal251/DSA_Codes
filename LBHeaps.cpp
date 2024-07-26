#include <bits/stdc++.h>
using namespace std;
#define int long long int

// node = i
// left child = i*2
// right child = i*2 + 1
// parent= i/2

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {

        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // step1:-put the last element into first index
        arr[1] = arr[size];

        // step2:-remove last element
        size--;

        // step3:-take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
                return;
        }
    }
};

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// void heapify(int arr[],int n,int i)
// {
//     int largest=i;
//     int left=2*i;
//     int right=2*i+1;

//     if(left<=n && arr[largest]<arr[left])
//     {
//         largest=left;
//     }
//     if(right<=n && arr[largest]<arr[right])
//     {
//         largest=right;
//     }

//     if(largest!=i)
//     {
//         swap(arr[largest],arr[i]);
//         heapify(arr,n,largest);
//     }
// }

// void heapify(int arr[], int n, int i)
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        swap(arr[largest], arr[left]);
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        swap(arr[largest], arr[right]);
        largest = right;
    }

    if (largest != i)
    {
        // swap(arr[largest],arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        // step1
        swap(arr[1], arr[size]);
        size--;

        // step2
        // heapify(arr, size, 1);   //commented due the change in heap func from array to vector
    }
}

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> p;

    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    for (int i = k; i <= r; i++)
    {
        if (arr[i] < p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    int ans = p.top();
    return ans; 
}

int countNodes(node* root)
{
    if(root==NULL)
    return 0;

    int ans=1+countNodes(root->left)+countNodes(root->right);
    return ans;
}

bool isCompleteBinaryTree(node *root, int index, int cnt)
{
    if(root==NULL)
    return true;

    if(index>=cnt)
    return false;

    else
    {
        bool left=isCompleteBinaryTree(root->left,2*index+1,cnt);
        bool right=isCompleteBinaryTree(root->right,2*index+2,cnt);
        return (left && right);
    }
}

bool isMaxorder(node*root)
{
    if(root==NULL)
    return true;

    if(root->left==NULL)
    return(root->data > root->right->data);

    else
    {
        bool left=isMaxorder(root->left);
        bool right=isMaxorder(root->right);

        if(left && right&& root->data>root->left->data && root->data>root->right->data)
        return true;
        else
        return false;
    }

}

bool isHeap(node* root )
{
    int index=0;
    int totalcount=countNodes(root);
    if(isMaxorder(root) && isCompleteBinaryTree(root,index,totalcount))
    return true;
    else
    return false;
}

vector<int> mergeHeap(vector<int> &a,vector<int> &b,int n,int m)
{
    //step1:-merge both arrays into one

    vector<int> ans;
    ans.push_back(-1);
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        ans.push_back(b[i]);
    }

    int n=ans.size();

    //step2:-build heap using merged array

    for (int i = n/2; i>0; i++)
    {
        heapify(ans,n,i);
    }
    
}

// there are given n roaps of differsent length we need to connect these roaps into one roap.the cost to connect two roaps is equal to sum of their length,the task is to connect roaps with min cost
int minCost(int arr[],int n)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    

    int cost=0;

    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();

        int sum=a+b;
        cost+=sum;

        pq.push(sum);
    }
    return cost;


}


int32_t main()
{
    // heap h;
    // // h.insert(50);
    // // h.insert(55);
    // // h.insert(53);
    // // h.insert(52);
    // // h.insert(54);
    // // h.print();

    // // h.deleteFromHeap();

    // // int arr[6]={-1,54,53,55,52,50};
    // int arr[6]={-1,54,55,53,52,50};
    // int n=5;
    // for (int i = n/2; i >0; i--)
    // {
    //     heapify(arr,n,i);
    // }
    // cout<<"printing the arrray"<<endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // heapSort(arr,n);

    // cout<<"Sorted Array"<<endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // h.print();

    // Priority queue
    // maxheap
    priority_queue<int> pq;

    pq.push(53);
    pq.push(50);
    pq.push(52);
    pq.push(55);
    pq.push(54);
    cout << "size is: " << pq.size() << endl;
    cout << "Top element is " << pq.top() << endl;
    pq.pop();
    cout << "Top element is " << pq.top() << endl;
    pq.pop();
    cout << "Top element is " << pq.top() << endl;
    pq.pop();
    cout << "Top element is " << pq.top() << endl;
    pq.pop();
    cout << "Top element is " << pq.top() << endl;

    // minheap
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(53);
    minheap.push(50);
    minheap.push(52);
    minheap.push(55);
    minheap.push(54);
    cout << "size is: " << minheap.size() << endl;
    cout << "Top element is " << minheap.top() << endl;
    minheap.pop();
    cout << "Top element is " << minheap.top() << endl;
    minheap.pop();
    cout << "Top element is " << minheap.top() << endl;
    minheap.pop();
    cout << "Top element is " << minheap.top() << endl;
    minheap.pop();
    cout << "Top element is " << minheap.top() << endl;

    return 0;
}