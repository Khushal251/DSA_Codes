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

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
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

vector<int> preorderTraversalIterative(node *root)
{
    vector<int> num;
    if (root == NULL)
        return num;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *temp = s.top();
        num.push_back(temp->data);
        s.pop();

        if (temp->right != NULL)
            s.push(temp->right);
        if (temp->left != NULL)
            s.push(temp->left);
    }
    return num;
}

vector<int> inorderTraversalIterative(node *curr)
{
    vector<int> inOrder;
    stack<node *> s;
    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty())
                break;
            curr = s.top();
            inOrder.push_back(curr->data);
            s.pop();
            curr = curr->right;
        }
    }
    return inOrder;
}

vector<int> postOrderTravUsing2Stack(node *curr)
{

    vector<int> postOrder;
    if (curr == NULL)
        return postOrder;

    stack<node *> s1;
    stack<node *> s2;
    s1.push(curr);
    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left != NULL)
            s1.push(curr->left);
        if (curr->right != NULL)
            s1.push(curr->right);
    }
    while (!s2.empty())
    {
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
    return postOrder;
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

void inorderForCountingLeafNodes(node *root, int &count)
{
    // base case
    if (root == NULL)
        return;

    inorderForCountingLeafNodes(root->left, count);

    if (root->left == NULL && root->right == NULL)
        count++;

    inorderForCountingLeafNodes(root->right, count);
}

int CountingLeafNode(node *root)
{
    int count = 0;
    inorderForCountingLeafNodes(root, count);
    return count;
}

// void inorderForHieght(node*root,int count,int &max)
// {

//     count++;
//     //base case
//     if(root==NULL)
//     return ;

//     inorderForHieght(root->left,count,max);

//     if(root->left==NULL && root->right==NULL)
//     {
//         if(count>max)
//         max=count;
//     }

//     inorderForHieght(root->right,count,max);

// }

// int hieght(node*root)
// {
//     int count=0;
//     int maxleft=0;
//     int maxright=0;
//     // int max=0;
//     inorderForHieght(root->left,count,maxleft);
//     inorderForHieght(root->left,count,maxright);
//     return max(maxleft,maxright)+1;

// }

int hieght(node *temp)
{
    // base case
    if (temp == NULL)
        return 0;

    int left = hieght(temp->left);
    int right = hieght(temp->right);

    int ans = max(left, right) + 1;
    return ans;
}

int diameter(node *root)
{
    // base case
    if (root == NULL)
        return 0;

    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = hieght(root->left) + hieght(root->right) + 1;

    int ans = max(opt3, max(opt1, opt2));
    return ans;
}

pair<int, int> diameterFast(node *root)
{
    // Base case
    if (root == NULL)
    {
        pair<int, int> p = {0, 0};
        return p;
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int Diameter(node *root)
{
    return diameterFast(root).first;
}

bool isBalanced(node *root)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(hieght(root->left) - hieght(root->right)) <= 1;

    if (left && right && diff)
        return 1;

    else
        return 0;
}

pair<bool, int> isBalancedFast(node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isBalancedNew(node *root)
{
    return isBalancedFast(root).first;
}

bool isIdentical(node *r1, node *r2)
{
    // base case
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<bool, int> isSumTreeFast(node *root)
{

    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = root->data == leftSum + rightSum;

    pair<bool, int> ans;

    if (isLeftSumTree && isRightSumTree && condn)
    {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isSumTree(node *root)
{
    return isSumTreeFast(root).first;
}

vector<int> zigZagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // Level Process
        for (int i = 0; i < size; i++)
        {
            node *frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            // the above line can also be written as
            //  if(leftToRight)
            //  {
            //      int index=i;
            //      ans[index]=frontNode->data;
            //  }
            //  else
            //  {
            //      int index=size-1-i;
            //      ans[index]=frontNode->data;

            // }
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);

            if (frontNode->right)
                q.push(frontNode->right);
        }

        // direction change karni h
        leftToRight = !leftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

void traverseLeft(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // wapas aagye
    ans.push_back(root->data);
}

vector<int> boundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // left part print/store
    traverseLeft(root->left, ans);

    // traverse Leaf Nodes

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}

vector<int> verticalOrder(node *root)
{
    map<int, map<int, vector<int>>> nodes; // map<hd, map<lvl, vector<int>>> nodes   only for storing the answer  you can use multiset instead of vector
    queue<pair<node *, pair<int, int>>> q; // queue<pair<node *, pair<Hd, lvl>>> q
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
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
    return ans;
}

vector<vector<int>> verticalOrder2(node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}}); // initial vertical and level
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        node *temp = p.first;

        // x -> vertical , y->level
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(temp->data); // inserting to multiset

        if (temp->left)
        {
            todo.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

vector<int> topView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for a HD, then do nothing
        if (topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

void doing(node *root, map<int, int> &m, int level)
{
    if (root == NULL)
        return;

    if (m.find(level) == m.end())
    {
        // cout<<"level: "<<level<<" "<<"data:"<<root->data<<endl;
        m[level] = root->data;
    }
    doing(root->right, m, level + 1);
    doing(root->left, m, level + 1);
}

vector<int> rightView(node *root)
{
    map<int, int> nodes;
    int level = 0;
    doing(root, nodes, level);

    // cout<<nodes[0]<<endl;
    // cout<<nodes[1]<<endl;
    // cout<<nodes[2]<<endl;

    // 1 2 3 -1 5 -1 4 -1 -1 -1 -1

    vector<int> v;
    for (auto i : nodes)
    {
        v.push_back(i.second);
        // cout<<i.second<<" ";
    }
    cout << endl;
    return v;
}

bool isSymmetricUtil(node *root1, node *root2)
{
    if (root1 == NULL || root2 == NULL)
        return root1 == root2;
        
    return (root1->data == root2->data) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
}
bool isSymmetric(node *root)
{
    if (!root)
        return true;
    return isSymmetricUtil(root->left, root->right);
}

int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;

        return -1;
    }
}

void createMappping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

node *solveIt(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    if (index >= n || inorderStart > inorderEnd)
        return NULL;

    int element = pre[index++];
    node *root = new node(element);
    // int position = findPosition(in,element,n);
    int position = nodeToIndex[element];

    root->left = solveIt(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
    root->right = solveIt(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);

    return root;
}

node *buildTreeWithInOrderAndPreOrder(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    // create node to index mapping
    createMappping(in, nodeToIndex, n);
    node *ans = solveIt(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

node *solveIt2(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    if (index < 0 || inorderStart > inorderEnd)
        return NULL;

    int element = post[index--];
    node *root = new node(element);
    // int position = findPosition(in,element,n);
    int position = nodeToIndex[element];

    // here left call comes first
    root->right = solveIt2(in, post, index, position + 1, inorderEnd, n, nodeToIndex);
    root->left = solveIt2(in, post, index, inorderStart, position - 1, n, nodeToIndex);

    return root;
}

node *buildTreeWithInOrderAndPostOrder(int in[], int post[], int n)
{
    int postOrderIndex = 0;
    map<int, int> nodeToIndex;
    // create node to index mapping
    createMappping(in, nodeToIndex, n);
    node *ans = solveIt2(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

node *createParentMapping(node *root, int target, map<node *, node *> &nodeToParent)
{
    node *res = NULL;
    queue<node *> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        node *frontNode = q.front();
        q.pop();

        if (frontNode->data == target)
            res = frontNode;

        if (frontNode->left)
        {
            nodeToParent[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }
        if (frontNode->right)
        {
            nodeToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }

    return res;
}

int BurnTree(node *root, map<node *, node *> &nodeToParent)
{
    map<node *, bool> visited;
    queue<node *> q;
    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // process neighbouring nodes
            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if (flag == 1)
            ans++;
    }
    return ans;
}

int minTimeToBurnaTree(node *root, int target)
{
    // algo:
    // step 1: create nodeToParent
    // step 2: find target node
    // step 3: burn the tree in min time

    map<node *, node *> nodeToParent;
    node *targetNode = createParentMapping(root, target, nodeToParent);

    int ans = BurnTree(targetNode, nodeToParent);
    return ans;
}

void MorrisTraversal(node *root)
{
    node *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {

            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } /* End of if condition pre->right == NULL */
        }     /* End of if condition current->left == NULL*/
    }         /* End of while */
}

int32_t main()
{
    node *root = NULL;

    // //Creating a Tree
    // root=buildTree(root);

    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // //level order traversal
    // cout<<"Printing the level order traversal output "<<endl;
    // levelOrderTraversal(root);
    // cout<<"Inorder traversal is "<<endl;
    // inorder(root);
    // cout<<endl;
    // cout<<"Preorder traversal is "<<endl;
    // preorder(root);
    // cout<<endl;
    // cout<<"Postorder traversal is "<<endl;
    // postorder(root);
    // cout<<endl;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    rightView(root);
    // 1 2 3 -1 5 -1 4 -1 -1 -1 -1
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // cout<<"Ther number of Leaf nodes are: "<<CountingLeafNode(root)<<endl;

    // cout<<hieght(root)<<endl;
    // cout<<Hieght(root)<<endl;
    // cout << diameter(root) << endl;

    return 0;
}
