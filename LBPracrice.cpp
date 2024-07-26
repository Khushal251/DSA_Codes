
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

vector<int> nextSmallestElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (s.top() < arr[i])
        {
            ans[i] = s.top();
            s.push(arr[i]);
            cout << "hello" << endl;
        }
        else
        {
            while (s.top() > arr[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(arr[i]);
        }
        cout << "At index " << i << " " << ans[i] << endl;
        ;
    }
    return ans;
}
vector<int> nextSmallest(vector<int> v)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (s.top() != -1 && v[s.top()] >= v[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> preSmallest(vector<int> v)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        while (s.top() != -1 && v[s.top()] >= v[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallest(heights);
    vector<int> pre(n);
    pre = preSmallest(heights);

    int area = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        if (next[i] == -1)
            next[i] = heights.size();

        int bredth = next[i] - pre[i] - 1;
        int hight = heights[i];
        int InsArea = bredth * hight;

        area = max(InsArea, area);
    }

    return area;
}

int trap(vector<int> &height)
{
    int n = height.size();
    int maxLeft = 0;
    int maxRight = 0;
    int left = 0;
    int right = n - 1;
    int res = 0;

    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }
            left++;
        }

        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }
            right--;
        }
    }

    return res;
}

vector<int> leftSmallerArray(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> rightSmallerArray(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && arr[s.top()] > arr[i])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int sumSubarrayMins(vector<int> &arr)
{

    int n = arr.size();

    vector<int> left(n);
    vector<int> right(n);
    left = leftSmallerArray(arr);
    right = rightSmallerArray(arr);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (right[i] == -1)
            right[i] = n;

        int x = i - left[i] - 1;
        int y = right[i] - i - 1;

        cout << "Number is: " << arr[i] << endl;
        cout << "x = " << x << " "
             << "y = " << y << endl;

        ans += ((x + 1) * (y + 1)) * arr[i];
    }
    cout << endl
         << "Ans is: " << ans << endl;

    // ans = ans % (10 ^ 9 + 7);
    cout << endl
         << "Ans is: " << ans << endl;

    return ans;
}

vector<int> asteroidCollision(vector<int> &arr)
{
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        if (arr[i] == abs(arr[i]))

            s.push(arr[i]);

        else if (arr[i] != abs(arr[i]))
        {
            if (s.top() != abs(s.top()))
                s.push(arr[i]);
            else
            {
                // cout << "yes" << endl;
                while (!s.empty() && abs(s.top()) == s.top() && abs(s.top()) < abs(arr[i]))
                    s.pop();

                if (s.empty())
                {
                    s.push(arr[i]);
                    continue;
                }

                if (s.top() == abs(arr[i]))
                {
                    s.pop();
                    continue;
                }
                if (!s.empty() && s.top() != abs(s.top()))
                    s.push(arr[i]);
            }
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        int x = s.top();
        ans.push_back(x);
        s.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> rightGreaterElements(vector<int> nums, int n)
{
    vector<long long> ans(n, -1);

    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }

        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }
    return ans;
}

vector<int> leftGreaterElements(vector<int> nums, int n)
{
    // Your code here
    // int n = nums.size();
    vector<long long> ans(n, -1);

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }

        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }
    return ans;
}

int sumSubarrayMax(vector<int> &arr)
{

    int n = arr.size();

    vector<int> left(n);
    vector<int> right(n);
    left = leftGreaterElements(arr, n);
    right = rightGreaterElements(arr, n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (right[i] == -1)
            right[i] = n;

        int x = i - left[i] - 1;
        int y = right[i] - i - 1;

        cout << "Number is: " << arr[i] << endl;
        cout << "x = " << x << " "
             << "y = " << y << endl;

        ans += ((x + 1) * (y + 1)) * arr[i];
    }

    cout << endl
         << "Ans is: " << ans << endl;

    // ans = ans % (10 ^ 9 + 7);
    cout << endl
         << "Ans is: " << ans << endl;

    return ans;
}

long long subArrayRanges(vector<int> &nums)
{

    int min = sumSubarrayMins(nums);
    int max = sumSubarrayMax(nums);

    return max - min;
}

string removeKdigits(string str, int k)
{
    vector<int> v;

    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        // s[i] - '0' would also work here
        v.push_back(str[i] - 48);
    }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    stack<int> s;
    s.push(v[0]);
    int count = 0;
    int i = 1;
    while (i < v.size())
    {
        cout << "yes" << endl;

        if (s.top() > v[i] && count < k)
        {
            cout << "andar" << endl;

            s.pop();
            count++;
        }
        s.push(v[i]);
        i++;
    }
    if (k - count == 1)
        s.pop();

    vector<int> ans;
    while (!s.empty())
    {
        int x = s.top();
        ans.push_back(x);
        s.pop();
    }

    // reserve(ans.begin(),ans.end());
    i = ans.size() - 1;
    while (ans[i] == 0 && ans.size() > 1)
    {
        ans.pop_back();
        i--;
    }
    // cout<<"a[i]: "<<ans[0]<<endl;

    reverse(ans.begin(), ans.end());

    // cout<<"ansSize: "<<ans.size()<<endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // cout<<"a[i]: "<<ans[0]<<endl;

    std::stringstream ss;

    for (int num : ans)
    {
        ss << num;
    }

    std::string stri = ss.str();
    std::cout << "Resulting string: " << stri << std::endl;
    return stri;
}

int maxElementInQueue(deque<int> q)
{

    if (q.empty())
        return -1;

    int maxx = INT_MIN;

    while (!q.empty())
    {

        int temp = q.front();
        q.pop_front();

        maxx = max(maxx, temp);
    }

    return maxx;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{

    deque<int> d;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if(!d.empty() && d.front() == i-k)
        d.pop_front();

        while(!d.empty() && nums[d.back()]<= nums[i])
        d.pop_back();

        d.push_back(i);

        if(i>=k-1)
        ans.push_back(nums[d.front()]);
    }

    return ans;
}

int32_t main()
{
    // node * node1=new node(10);
    // node *head = new node(10);
    // node *tail = head;
    // insertatfirst(head, 20);
    // insertatfirst(head, 30);
    // insertatend(head, tail, 40);
    // insertatpossition(head, tail, 5, 25);
    // traversal(head);
    // cout<<"head : "<<head->data<<endl;
    // cout<<"tail : "<<tail->data<<endl;

    // insertatend(head, tail, 20);
    // insertatend(head, tail, 30);
    // insertatend(head, tail, 40);
    // insertatend(head, tail, 50);
    // insertatend(head, tail, 60);
    // traversal(head);
    // deleteatpossition(head, tail, 1);
    // deleteatpossition(head, tail, 5);
    // cout << "head : " << head->data << endl;
    // cout << "tail : " << tail->data << endl;
    // reverse(head);
    // traversal(head);
    // node * temp=middlenode(head);
    // cout<<temp->data<<endl;
    // cout<<getlength(head);

    // head= kreverse(head, 3);
    // traversal(head);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans=maxSlidingWindow(v,2);

    // string s;
    // cin >> s;

    // sumSubarrayMax(v);

    // vector<int> ans = sumSubarrayMax(v);
    // removeKdigits(s, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
