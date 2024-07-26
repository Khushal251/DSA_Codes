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

node *buildTree(node *root)
{
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data to the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
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
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void storingLeafNode(node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    storingLeafNode(root->left, v);
    if (root->left == NULL && root->right == NULL)
        v.push_back(root->data);
    storingLeafNode(root->right, v);
}

void countingLeafNodes(node *root)
{
    vector<int> v;
    storingLeafNode(root, v);
    cout << "The number of leaf nodes are: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void inorderForHieght(node *root, int count, int &max)
{
    count++;
    if (root == NULL)
        return;

    inorderForHieght(root->left, count, max);

    if (root->left == NULL && root->right == NULL)
    {
        if (count > max)
            max = count;
    }

    inorderForHieght(root->right, count, max);
}

int hieght1(node *root)
{
    int count = 0;
    int leftMax = 0;
    int rightMax = 0;

    inorderForHieght(root->left, count, leftMax);
    inorderForHieght(root->right, count, rightMax);

    return max(leftMax, rightMax) + 1;
}

int hieght2(node *root)
{
    if (root == NULL)
        return 0;

    int left = hieght2(root->left);
    int right = hieght2(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int common = hieght2(root->left) + hieght2(root->right) + 1;

    int ans = max(max(leftDiameter, rightDiameter), common);
    return ans;
}

bool isBalanced(node *root)
{
    if (root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    int leftHieght = hieght2(root->left);
    int rightHieght = hieght2(root->right);
    bool check = abs(leftHieght - rightHieght) <= 1;
    if (check && left && right)
        return true;
    else
        return false;
}

bool isSame(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 != NULL && root2 == NULL)
        return false;
    else if (root1 == NULL && root2 != NULL)
        return false;

    bool left = isSame(root1->left, root2->left);
    bool right = isSame(root1->right, root2->right);
    bool check = root1->data == root2->data;

    if (left && right && check)
        return true;
    else
        return false;
}

// void zigzagTraversal(node *root)
// {
//     queue<node *> q;
//     q.push(root);
//     q.push(NULL);

//     bool x = true;

//     while (!q.empty())
//     {
//         node *temp = q.front();
//         q.pop();
//         if (temp == NULL)
//         {
//             cout << endl;
//             x = !x;
//             if (!q.empty())
//                 q.push(NULL);
//         }
//         else if(temp != NULL && x)
//         {
//             cout << temp->data << " ";

//             if (temp->right)
//                 q.push(temp->right);
//             if (temp->left)
//                 q.push(temp->left);
//         }
//         else if(temp != NULL && !x)
//         {
//             cout << temp->data << " ";

//             if (temp->left)
//                 q.push(temp->left);
//             if (temp->right)
//                 q.push(temp->right);
//         }
//     }
// }

vector<int> zigzagTraverdsl(node *root)
{

    vector<int> result;
    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);

    bool check = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();

            if (check)
            {
                int index = i;
                ans[index] = temp->data;
            }
            else
            {
                int index = size - 1 - i;
                ans[index] = temp->data;
            }

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        check = !check;

        for (int i = 0; i < size; i++)
        {
            result.push_back(ans[i]);
        }
    }
    return result;
}

vector<int> verticalOrder(node *root)
{
    vector<int> ans;
    map < int, map<int, vector<int>>> nodes;
    queue<pair<node*,pair<int, int>>> q;

    q.push({root,{0,0}});

    while(!q.empty())
    {
        pair<node*,pair<int, int>> temp=q.front();
        q.pop();

        node* frontNode=temp.first;
        int hd=temp.second.first;
        int lev=temp.second.second;

        nodes[hd][lev].push_back(frontNode->data);

        if(frontNode->left)
        q.push({frontNode->left,{hd-1,lev+1}});
        if(frontNode->left)
        q.push({frontNode->left,{hd+1,lev+1}});




    }
     for (auto i : nodes)
    {

        for (auto j : i.second)
        {

            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }



}

int32_t main()
{
    node *root = NULL;
    root = buildTree(root);
    cout << "Level Order traversal " << endl;
    levelOrderTraversal(root);
    // cout << "InorderOrder traversal " << endl;
    // inorder(root);
    // cout << endl;
    // 10 8 4 -1 -1 3 2 -1 -1 -1 12 14 -1 -1 13 -1 -1

    // countingLeafNodes(root);
    cout << "ZigZag traversal " << endl;
    // zigzagTraversal(root);

    return 0;
}
