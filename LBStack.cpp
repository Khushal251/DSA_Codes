#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Stack
{
    // properties
public:
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Implementing Two Stack in one Array
class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialise two stacks
    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1
    void push1(int num)
    {
        // at least an empty space present
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    // Push in Stack 2
    void push2(int num)
    {
        // at least an empty space present
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    // pop from stack 1 and returned poped element
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // pop from stack 2 and returned poped element
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

void ReverseAStringUsingStack(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    string ans = "";
    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout << ans << endl;
}

void solve(stack<int> &inputstack, int count, int size)
{
    // Base Case
    if (count == size / 2)
    {
        inputstack.pop();
        return;
    }

    int num = inputstack.top();
    inputstack.pop();

    // Recursive Call
    solve(inputstack, count + 1, size);

    inputstack.push(num);
}

void DeletingMiddleNodeUsingStack(vector<int> v, int n)
{
    stack<int> inputstack;
    for (int i = 0; i < v.size(); i++)
    {
        inputstack.push(v[i]);
    }

    int count = 0;
    solve(inputstack, count, n);
    // string ans="";
    vector<int> ans;

    for (int i = 0; i < v.size() - 1; i++)
    {
        // cout<<inputstack.top();
        ans.push_back(inputstack.top());
        inputstack.pop();
    }
    // cout<<ans<<endl;
    // ReverseAStringUsingStack(ans);
    // cout<<ans<<endl;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;
}

bool isValidParenthesis(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(' || (ch == '}' && top == '{') || (ch == ']' && top == '[')))
                {
                    s.pop();
                }
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}

void InsertAtBottomofStack(stack<int> s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    InsertAtBottomofStack(s, x);

    s.push(num);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;

    int num = s.top();
    s.pop();

    reverseStack(s);

    InsertAtBottomofStack(s, num);
}

void sortedInsert(stack<int> &stack, int num)
{
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    sortedInsert(stack, num);

    stack.push(n);
}

void sortedStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    sortedStack(stack);

    sortedInsert(stack, num);
}

bool RedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else
        {
            // ch ya thi ')' hai or lowercase letter

            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        isRedundant = false;

                    st.pop();
                }
                if (isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}

int findMinimumCost(string str)
{
    // odd condition
    if (str.length() % 2 == 1)
        return -1;

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
            s.push(ch);
        else
        {
            // ch is closed brace
            if (!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(ch);
        }
    }

    // stack contains invalid expression
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
            b++;
        else
            a++;

        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (s.top() < arr[i])
        {
            ans[i] = s.top();
            s.push(arr[i]);
        }
        else
        {
            while (s.top() >= arr[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(arr[i]);
        }
    }
    return ans;
}

vector<int> PreviousSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < arr.size(); i++)
    {

        while (s.top() >= arr[i])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

vector<int> nextSmallestElementArea(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
            s.pop();

        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> preSmallestElementArea(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
            s.pop();

        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleAreaInHistogram(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallestElementArea(heights, n);

    vector<int> pre(n);
    pre = preSmallestElementArea(heights, n);

    int area = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
            next[i] = n;

        int b = next[i] - pre[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else
    {
        // If the element is not
        // present in the vector
        return -1;
    }
}

vector<int> nextGreaterElements(vector<int> nums, int n)
{
    // Your code here
    // int n = nums.size();
    vector<long long> ans(n, -1);

    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }

        if (!st.empty())
            ans[i] = st.top();

        st.push(nums[i]);
    }
    return ans;
}

vector<int> nextGreaterElementsCircular(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            if (!st.empty())
                nge[i] = st.top();
        }
        st.push(nums[i % n]);
    }
    return nge;
}

void nextG(vector<int> &num1, vector<int> &num2, vector<int> &ans)
{
    // vector<int> ans;
    vector<int> greater;
    greater = nextGreaterElements(num2, num2.size());

    // nextGratestElement(num2, greater);
    // cout << "Yes" << endl;
    // cout << "Next Greater element are: " << endl;

    // for (int i = 0; i < greater.size(); i++)
    // {
    //     cout << greater[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < num1.size(); i++)
    {
        int index = getIndex(num2, num1[i]);
        int curr = greater[index];
        ans.push_back(curr);
    }

    // return ans;
}
int getIndexSet(set<int> v, int K)
{
}

vector<int> countGreater(vector<int> &arr, vector<int> &query)
{
    multiset<int> s;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }
    for (int i = 0; i < query.size(); i++)
    {
        int num = arr[query[i]];
        auto pos = s.find(num);
        int index = distance(s.begin(), pos);
        ans.push_back(arr.size() - index - 1);
    }
    return ans;
}

void countGrater2(vector<int> A)
{
    int n = A.size();
    int right[n];
    stack<pair<int, int>> s2;
    for (int i = n - 1; i >= 0; --i)
    {
        int cnt = 1;

        // get elements from stack until element greater
        // or equal to A[i] found
        while (!s2.empty() && (s2.top().first) >= A[i])
        {
            cnt += s2.top().second;
            s2.pop();
        }

        s2.push({A[i], cnt});
        right[i] = cnt;
        cout << s2.top().first << " " << s2.top().second << endl;
    }

    for (int i = 0; i < A.size(); i++)
    {
        cout << right[i] << " ";
    }
    cout << endl;
}

int trapWater1(vector<int> &arr)
{
    int n = arr.size();
    int prefix[n], suffix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}

int trappedWater2(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
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

    ans = ans % (10 ^ 9 + 7);
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

long long subArrayRanges(vector<int> &nums)
{

    int min = sumSubarrayMins(nums);
    int max = sumSubarrayMax(nums);

    return max - min;
}

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;

        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;

        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            node *resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }

        return -1;
    }

    void put(int key_, int value)
    {
        if (m.find(key_) != m.end())
        {
            node *existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};

int32_t main()
{
    // stack<int> s;
    // s.push(10);
    // cout << s.top() << endl;

    // if (s.empty())
    // {
    //     cout << "stack is empty" << endl;
    // }
    // else
    // {
    //     cout << "stack is not empty" << endl;
    // }
    // cout << s.size() << endl;

    // Stack st(5);
    // st.push(10);
    // st.push(20);
    // st.push(30);

    // cout << st.peek() << endl;
    // st.pop();
    // cout << st.peek() << endl;
    // st.pop();
    // st.pop();
    // cout << st.peek() << endl;

    // ReverseAStringUsingStack("babbar");
    int n, m;
    cin >> n;
    // cin >> m;
    vector<int> num1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
    }
    // vector<int> num2(m);
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> num2[i];
    // }

    countGrater2(num1);

    // DeletingMiddleNodeUsingStack(v, 6);
    // vector<int> ans;
    // nextGratestElement(v,ans);
    // nextG(num1, num2, ans);
    // vector<int> ans(n, -1);
    // nextGreaterElements(num1, ans);
    // for (int i = 0; i < num1.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    // multiset<int> s;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin>>x;
    //     s.insert(x);
    // }
    // for(auto value: s)
    // {
    //     cout<<value<<" ";
    // }
    // cout << endl;

    return 0;
}
