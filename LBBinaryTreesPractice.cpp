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
    cout << "Enter the data" << endl;
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
                q.push(NULL);
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

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
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

int hieght(node *root)
{
    if (root == NULL)
        return 0;

    int left = hieght(root->left);
    int right = hieght(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = hieght(root->left) + hieght(root->right) + 1;

    int ans = max(max(opt1, opt2), opt3);
    return ans;
}

pair<int, int> Diam(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = {0, 0};
        return p;
    }

    pair<int, int> left = Diam(root->left);
    pair<int, int> right = Diam(root->right);

    pair<int, int> ans;

    ans.first = max(max(left.first, right.first), left.second + right.second + 1);
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameterFast(node *root)
{
    pair<int, int> p;
    p = Diam(root);
    return p.first;
}

int suming(node *root)
{
    if (root == NULL)
        return 0;

    int left = suming(root->left);
    int right = suming(root->right);

    int ans = left + right + root->data;
    return ans;
}

bool sumTree(node *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    bool left = sumTree(root->left);
    bool right = sumTree(root->right);
    bool diff = ((suming(root->left) + suming(root->right)) == root->data);

    // cout<<"Left: "<<left<<" "<<"Right: "<<right<<" "<<"diff: "<<diff<<endl;

    return (left && right && diff);
}

pair<bool, int> sumSolve(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = {true, 0};
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = {true, root->data};
        return p;
    }

    pair<bool, int> left = sumSolve(root->left);
    pair<bool, int> right = sumSolve(root->right);

    bool opt1 = left.first;
    bool opt2 = right.first;
    bool opt3 = left.second + right.second == root->data;

    pair<bool, int> ans;
    ans.first = opt1 && opt2 && opt3;
    ans.second = left.second + right.second + root->data;

    return ans;
}

bool sumTree2(node *root)
{
    pair<bool, int> p = sumSolve(root);
    return p.first;
}

vector<int> ZigZag(node *root)
{
    vector<int> result;
    
    if(root==NULL)
    return result;

    queue<node *> q;
    q.push(root);
    bool isTrue = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);

        for (int i = 0; i < size; i++)
        {
            node *frontNode = q.front();
            q.pop();

            if (isTrue)
            {
                int index = i;
                temp[index] = frontNode->data;
            }
            else
            {
                int index = size - i - 1;
                temp[index] = frontNode->data;
            }

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }

        isTrue = !isTrue;
        for (int i = 0; i < size; i++)
        {
            result.push_back(temp[i]);
        }
    }
    return result;
}

int32_t main()
{
    node *root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 3 1 2 -1 -1 -1 -1
    // cout << "The answer is " << endl;
    // cout << sumTree(root) << endl;

    vector<int> ans = ZigZag(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}