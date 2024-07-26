#include <bits/stdc++.h>
using namespace std;
#define int long long int

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

node *insertIntoBST(node *root, int d)
{
    // Base case;
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        // right part mai insert karna hai
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // left part mai insert karna hai
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root) // LNR
{
    // base case
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root) // NLR
{
    // base case
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) // LRN
{
    // base case
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool searchInBST(node *root, int data)
{
    if (root->data == data)
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }

    if (data > root->data)
    {
        return searchInBST(root->right, data);
    }
    else
    {
        return searchInBST(root->left, data);
    }
}
node *searchNodeInBST(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }

    if (data > root->data)
    {
        return searchNodeInBST(root->right, data);
    }
    else
    {
        return searchNodeInBST(root->left, data);
    }
}

node *minValue(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node *maxValue(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

void good(node *root, int &ans, int k)
{
    if (root == NULL)
        return;

    if (root->data >= k)
    {
        ans = root->data;
        good(root->left, ans, k);
        return;
    }
    if (root->data < k)
    {
        good(root->right, ans, k);
    }
}

int findCeil(node *root, int x)
{
    // Write your code here.

    int ans = -1;

    good(root, ans, x);

    return ans;
}

void alpha(node *root, int &ans, int k)
{
    if (root == NULL)
        return;

    if (root->data == k)
    {
        ans = root->data;

        return;
    }
    if (root->data < k)
    {
        ans = root->data;
        alpha(root->right, ans, k);
        return;
    }
    if (root->data > k)
    {
        alpha(root->left, ans, k);
    }
}

int Floor(node *node, int input)
{
    int ans = -1;

    alpha(node, ans, input);

    return ans;
}

node *insertIntoBST(node *root, int val)
{

    if (root == NULL)
        return new node(val);

    node *temp = root;

    while (true)
    {
        if (temp->data <= val)
        {
            if (temp->right != NULL)
                temp = temp->right;

            else
            {
                temp->right = new node(val);
                break;
            }
        }
        else
        {
            if (temp->left != NULL)
                temp = temp->left;

            else
            {
                temp->left = new node(val);
                break;
            }
        }
    }
    return root;
}

node *deleteFromBST(node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {

        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int min = minValue(root->right)->data; // or you can get the value of max element from the left subtree and do the same process
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }
    }

    else if (root->data > val)
    {
        // left part mai jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        // right part mia jao
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

bool isBST(node *root, int min, int max)
{
    // base case
    if (root == NULL)
        return true;

    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
        return false;
}

bool validBST(node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int solve(node *root, int &i, int k)
{
    // base case
    if (root == NULL)
        return -1;

    int left = solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    // N
    i++;
    if (i == k)
        return root->data;

    // R
    return solve(root->right, i, k);
}

int kthSmallestBinaryNode(node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

void PredecessorSuccessor(node *root, int key)
{
    node *temp = root;
    int pre = -1;
    int suc = -1;

    // Find key
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            suc = temp->data;
            temp = temp->left;
        }
        else
        {
            pre = temp->data;
            temp = temp->right;
        }
    }
    // cout << "temp: " << temp->data << endl;

    if (temp->left != NULL)
    {
        pre = maxValue(temp->left)->data;
    }
    if (temp->right != NULL)
    {

        suc = minValue(temp->right)->data;
    }

    cout << "predecessor: " << pre << endl;
    cout << "Successor: " << suc << endl;

    // pair<int,int> ans={predecessor,Successor};
    // return ans;
}

node *lastCommonAnsistor(node *root, int p, int q)
{
    if (root == NULL)
        return NULL;

    if (root->data < p && root->data < q)
    {
        return lastCommonAnsistor(root->left, p, q);
    }

    if (root->data > p && root->data > q)
    {
        return lastCommonAnsistor(root->right, p, q);
    }

    return root;
}

void inorderVector(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    inorderVector(root->left, v);
    v.push_back(root->data);
    inorderVector(root->right, v);
}

bool twoSumBST(node *root, int target)
{
    vector<int> v;
    inorderVector(root, v);

    int i = 0;
    int j = v.size()-1;

    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == target)
            return true;

        else if (sum > target)
            j--;

        else
            i++;
    }
    return false;
}

void preOrderVector(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    v.push_back(root->data);
    preOrderVector(root->left, v);
    preOrderVector(root->right, v);
}

node *flattenBSTtoLinkedList(node *root)
{
    vector<int> v;
    preOrderVector(root, v);

    node *newNode = new node(v[0]);
    node *curr = newNode;

    for (int i = 1; i < v.size(); i++)
    {
        node *temp = new node(v[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newNode;
}

node *inordertoBST(int s, int e, vector<int> v)
{
    // base case
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    node *root = new node(v[mid]);
    root->left = inordertoBST(s, mid - 1, v);
    root->right = inordertoBST(mid + 1, e, v);
    return root;
}

node *NormalBSTtobBalancedBST(node *root)
{
    vector<int> v;
    inorderVector(root, v);

    return inordertoBST(0, v.size() - 1, v);
}

node *solving(vector<int> &v, int mini, int maxi, int &i)
{
    if (i >= v.size())
        return NULL;

    if (v[i] < mini || v[i] > maxi)
        return NULL;

    node *root = new node(v[i++]);
    root->left = solving(v, mini, root->data, i);
    root->right = solving(v, root->data, maxi, i);
    return root;
}

node *preorderToBST(vector<int> &v)
{
    int mini = LLONG_MIN;
    int maxi = LLONG_MAX;
    int i = 0;
    return solving(v, mini, maxi, i);
}

vector<int> mergeArrays(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[i])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }
    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

node *mergeTwoBSTApproch1(node *root1, node *root2)
{
    vector<int> bst1, bst2;
    inorderVector(root1, bst1);
    inorderVector(root2, bst2);

    vector<int> mergeArray = mergeArrays(bst1, bst2);

    int s = 0, e = mergeArray.size() - 1;
    return inordertoBST(s, e, mergeArray);
}

node *BSTtoSortedDoublyLinkedlist(node *root, node *&head)
{
    if (root == NULL)
        return NULL;

    BSTtoSortedDoublyLinkedlist(root->right, head);

    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    BSTtoSortedDoublyLinkedlist(root->left, head);
}

node *mergeLinkedList(node *head1, node *head2)
{
    node *head = NULL;
    node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    return head;
}

int countNodes(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

node *sortedLinkedListToBST(node *&head, int n)
{
    // Base case
    if (n <= 0 || head == NULL)
        return NULL;

    node *left = sortedLinkedListToBST(head, n / 2);

    node *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLinkedListToBST(head, n - n / 2 - 1);
    return root;
}

node *mergeTwoBSTApproch2(node *root1, node *root2)
{
    // step1: convert BST into Sorted Doubly LinkedList in place
    node *head1 = NULL;
    BSTtoSortedDoublyLinkedlist(root1, head1);
    head1->left = NULL;

    node *head2 = NULL;
    BSTtoSortedDoublyLinkedlist(root2, head2);
    head2->left = NULL;

    // step2: merge sorted LinkedList
    node *head = mergeLinkedList(head1, head2);

    // step3: convert Sorted LinkedList into BST
    return sortedLinkedListToBST(head, countNodes(head));
}

class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, ans};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    // answer update
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int32_t main()
{
    node *root = NULL;

    // cout << "Enter data to creatr BST" << endl;
    // takeInput(root);
    // cout << "Level order Traversal" << endl;
    // levelOrderTraversal(root);
    // cout << "Inorder" << endl; // Inorder is always sorted
    // inorder(root);
    // cout << endl;
    // cout << "Preorder" << endl;
    // preorder(root);
    // cout << endl;
    // cout << "postorder" << endl;
    // postorder(root);
    // cout << endl;

    // cout<<"Enter the number to be search"<<endl;
    // int x;
    // cin>>x;
    // if(searchInBST(root,x))
    // cout<<"The elementis present"<<endl;
    // else
    // cout<<"The element is not present"<<endl;

    // if(searchNodeInBST(root,x))
    // cout<<"The node is present"<<endl;
    // else
    // cout<<"The node is not present"<<endl;

    // 8 21 7 27 5 4 3 -1

    // cout << "Min Value is: " << minValue(root)->data << endl;
    // cout << "Max Value is: " << maxValue(root)->data << endl;

    // root=deleteFromBST(root,50);
    // cout<<"kth smallest number is "<<kthSmallestBinaryNode(root,3)<<endl;
    // 50 20 70 10 30 90 110 -1
    // cout << "Level order Traversal" << endl;
    // levelOrderTraversal(root);

    // 5 3 6 2 4 1 -1
    // 5 4 8 2 6 10 3 7 -1

    // cout<<"predecessor: "<<PredecessorSuccessor(root,4).first<<endl;
    // cout<<"Successor: "<<PredecessorSuccessor(root,4).second<<endl;
    // PredecessorSuccessor(root, 10);
    // cout<<"lastCommonAnsistor: "<<lastCommonAnsistor(root,2,8)->data<<endl;

    // cout<<twoSumBST(root,16)<<endl;

    // root=flattenBSTtoLinkedList(root);
    // root = NormalBSTtobBalancedBST(root);

    int x;
    cin >> x;
    vector<int> v(x);
    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }

    root = preorderToBST(v);
    cout << "Level order Traversal" << endl;
    levelOrderTraversal(root);

    return 0;
}
