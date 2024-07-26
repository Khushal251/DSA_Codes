#include <bits/stdc++.h>
using namespace std;
#define int long long int

void printVec(vector<int> v)
{
    cout << "size : " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printVec2D(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(vector<int> &nums)
{
    int n = nums.size();
    int minIndex;
    int minval = LLONG_MAX;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < minval)
        {
            minval = nums[i];
            minIndex = i;
        }
    }
    // cout<<minIndex<<endl;
    // return true;

    // int c = 0;
    // int k = minIndex;
    // while (c < n-1)
    // {
    //     if (k == n - 1)
    //     {
    //         if (nums[0] < nums[k])
    //             return false;
    //         k = 0;
    //         c++;
    //         continue;
    //     }
    //     else if (nums[k + 1] < nums[k])
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         c++;
    //         k++;
    //     }
    // }
    // return true;
}

int removeDuplicates(vector<int> &nums)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    map<int, int>::iterator it = m.begin();
    for (int i = 0; i < m.size(); i++)
    {
        nums[i] = (*it).first;
        it++;
    }
    printVec(nums);
    return m.size();
}

void rotate(vector<int> &nums, int k)
{

    rotate(nums.begin(), nums.begin() + nums.size() - k, nums.end());
    printVec(nums);
}
void moveZeroes(vector<int> &nums)
{
    int n1 = nums.size();
    vector<int>::iterator it = nums.begin();
    for (int i = 0; i < n1; i++)
    {
        if (nums[i] == 0)
        {
            it = nums.begin() + i;
            nums.erase(it);
            i--;
            // nums.push_back(0);
        }
    }
    int n2 = nums.size();

    for (int i = 0; i < n1 - n2; i++)
    {
        nums.push_back(0);
    }

    printVec(nums);
}

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size(); i++)
    {
        if (nums[i] != i)
            return i;
    }
}
int missingNumber2(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    int i = 1;
    for (auto value : s)
    {
        // cout<<value<<" ";
        if (value != i + 1)
            return i + 1;
        i++;
    }
    // cout<<endl;
    return i + 1;
}

int findMaxConsecutiveOnes(vector<int> &nums)
{

    bool check = false;
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1 && check == true)
        {
            count++;
            maxCount = max(maxCount, count);
            check = true;
        }
        else if (nums[i] == 1 && check == false)
        {
            count++;
            maxCount = max(maxCount, count);
            check = true;
        }
        else if (nums[i] == 0)
        {
            check = false;
            count = 0;
            // cout<<"used"<<endl;
        }
        // cout<<maxCount<<endl;
        // cout << count << endl;
    }
    return maxCount;
}

int singleNumber(vector<int> &nums)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    map<int, int>::iterator it = m.begin();
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second == 1)
            return (*it).first;
    }
}

int doing(vector<int> &nums, int currIndex, int sum, int &k)
{
    if (currIndex > nums.size() - 1)
        return 0;
    if (sum > k)
        return 0;
    if (sum == k)
        return 1;

    int inc = doing(nums, currIndex + 1, sum + nums[currIndex], k);
    int exc = doing(nums, currIndex + 1, sum, k);

    return max(inc, exc);
}

void lenOfLongSubarr(vector<int> nums)
{
    int k = 15;
    cout << doing(nums, 0, 15, k);
}

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int>::iterator it = nums.begin();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {

        int ser = target - nums[i];
        it = find(nums.begin() + i + 1, nums.end(), ser);
        if (it != nums.end())
        {
            ans.push_back(i);
            ans.push_back(it - nums.begin());
            cout << "ans" << endl;

            break;
        }
    }
    return ans;
}

void sortColors(vector<int> &nums)
{
    // int n1 = nums.size();
    // int one = 0, two = 0;

    // vector<int>::iterator it = nums.begin();
    // for (int i = 0; i < n1; i++)
    // {
    //     if (nums[i] == 1)
    //     {
    //         it = nums.begin() + i;
    //         nums.erase(it);
    //         i--;
    //         one++;
    //     }
    //     else if (nums[i] == 2)
    //     {
    //         it = nums.begin() + i;
    //         nums.erase(it);
    //         i--;

    //         two++;
    //     }
    // }

    // for (int i = 0; i < one; i++)
    // {
    //     nums.push_back(1);
    // }
    // for (int i = 0; i < two; i++)
    // {
    //     nums.push_back(2);
    // }
    // printVec(nums);

    int n = nums.size();
    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int majorityElement(vector<int> &nums)
{

    int n = nums.size();
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }

    map<int, int>::iterator it = m.begin();
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second >= n / 2)
            return (*it).first;
    }
}

int majorityElement(int a[], int size)
{

    int n = size;
    map<int, int> m;
    for (int i = 0; i < size; i++)
    {
        m[a[i]]++;
    }

    map<int, int>::iterator it = m.begin();
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second > n / 2)
            return (*it).first;
    }
    return -1;
}

int maxSubArray(vector<int> &nums)
{
    int sum = 0, maxi = LLONG_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];

        maxi = max(maxi, sum);

        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

void rearrangeArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int pos = 0;
    int neg = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            ans[neg] = nums[i];
            neg = neg + 2;
        }
        else if (nums[i] >= 0)
        {
            ans[pos] = nums[i];
            pos = pos + 2;
        }
    }

    // printVec(ans);
}

void nextPermutation(vector<int> &v)
{
    int n = v.size();
    int c = 0;
    // cout<<n<<endl;
    for (int i = n - 1; i >= 1; i--)
    {
        if (v[i] > v[i - 1])
            c++;

        // cout << "YES" << endl;
        if (v[i] > v[i - 1])
        {
            if (i - 1 == 0)
            {
                cout << "check 1" << endl;
                v[i - 1] = v[i - 1] + 1;
                int num = v[i - 1];
                int k = 1;
                for (int j = 1; j < n; j++)
                {
                    if (k == num)
                        k++;
                    v[j] = k;
                    k++;
                }
                printVec(v);
                return;
            }
            else
            {
                // cout<<check 1<<endl;
                cout << "check 2" << endl;

                int num = v[i] - 1;
                int k = 1;
                swap(v[i], v[i - 1]);

                for (int j = i; j < n; j++)
                {
                    v[j] = k;
                    k++;
                }
                printVec(v);
                return;
            }
        }
    }
    cout << c;
    if (c == n - 1)
    {
        swap(v[n - 2], v[n - 1]);
        printVec(v);
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {

        v[i] = i + 1;
    }
    printVec(v);
    return;
}

int longestConsecutive(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }

    int maxi = 0;

    for (int num : nums)
    {
        if (!s.count(num - 1))
        {
            int currNum = num;
            int count = 1;
            while (s.count(currNum + 1))
            {
                currNum++;
                count++;
            }
            maxi = max(count, maxi);
        }
    }
    return maxi;
}

void setZeroes(vector<vector<int>> &matrix)
{

    vector<int> row(matrix.size(), 0);
    vector<int> col(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroes2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                if (matrix[i + 1][j] != 0 && i + 1 < n)
                    matrix[i + 1][j] = -1;

                if (matrix[i - 1][j] != 0 && i - 1 >= 0)
                    matrix[i - 1][j] = -1;

                if (matrix[i][j + 1] != 0 && j + 1 < m)
                    matrix[i][j + 1] = -1;

                if (matrix[i][j - 1] != 0 && j - 1 >= 0)
                    matrix[i][j - 1] = -1;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> v;
    int n = numRows;
    vector<int> ini;
    ini.push_back(1);
    // v[0].push_back(1);
    v.push_back(ini);
    // cout<<v[0][0]<<endl;
    for (int i = 1; i < n; i++)
    {
        // cout << "YES" << endl;
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                temp.push_back(1);
            }
            else
            {
                temp.push_back(v[i - 1][j - 1] + v[i - 1][j]);
            }
            // cout << v[i][j] << " ";
        }
        // printVec(temp);
        v.push_back(temp);
        // cout << endl;
    }

    printVec2D(v);
}

vector<int> majorityElement2(vector<int> &nums)
{
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    map<int, int>::iterator it = m.begin();
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second > (nums.size() / 3))
        {
            ans.push_back((*it).first);
        }
    }
    return ans;
}

vector<vector<int>> merge(vector<vector<int>> &v)
{
    sort(v.begin(), v.end());

    vector<vector<int>> ans;
    int n = v.size();
    for (int i = 0; i < v.size() - 1; i++)
    {

        if (v[i + 1][0] <= v[i][1])
        {
            vector<int> temp;
            temp.push_back(v[i][0]);
            temp.push_back(v[i + 1][1]);
            ans.push_back(temp);
            i++;
        }
        else
        {
            vector<int> temp;
            temp.push_back(v[i][0]);
            temp.push_back(v[i][1]);
            ans.push_back(temp);
        }
    }
    if (v[n - 1][0] > v[n - 2][1])
    {
        vector<int> temp;
        temp.push_back(v[n - 1][0]);
        temp.push_back(v[n - 1][1]);
        ans.push_back(temp);
    }

    printVec2D(ans);
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while (i < m)
    {
        ans.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(nums2[j]);
        j++;
    }
    // printVec(ans);
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = ans[i];
    }
}

int maxProduct(vector<int> &a)
{
    int n = a.size();
    int neg = 0, pro = 1;
    if (n == 1)
        return a[0];
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
            neg++;
        pro = pro * a[i];
    }
    // cout<<"pro: "<<pro<<endl;

    if (neg % 2 == 0)
        return pro;

    else
    {
        int l = 0;
        int r = n - 1;
        int left = a[0];
        int right = a[n - 1];
        int ans1 = pro;
        int ans2 = pro;
        while (a[l] >= 0)
        {

            ans1 = ans1 / a[l];
            l++;
            // cout<<"ans1 here is: "<<ans1<<endl;
        }
        ans1 = ans1 / a[l];

        while (a[r] >= 0)
        {
            ans2 = ans2 / a[r];
            r--;
            // cout<<"ans2 here is: "<<ans2<<endl;
        }
        ans2 = ans2 / a[r];

        // cout<<"left: "<<left<<endl;
        // cout<<"right: "<<right<<endl;
        // if(abs(left)>=abs(right))
        // return abs(pro-left);
        // else
        // return abs(pro-right);
        // cout << "ans1: " << ans1 << endl;
        // cout << "ans2: " << ans2 << endl;
        return max(ans1, ans2);
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);

            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int counting(vector<int> &arr, int low, int high, int mid, int &count)
{
    // int count=0;
    // for (int i = low; i <= mid; i++)
    // {
    //     int j = mid + 1;
    //     while (arr[j] < arr[i] && j <= high)
    //     {
    //         count++;
    //         // cout<<"("<<i<<","<<j<<")"<<"   ";
    //         // cout<<"low= "<<low<<", "<<"mid= "<<mid<<", "<<"high= "<<high <<"    "<<"(a[i],a[j])="<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
    //         j++;

    //     }
    // }

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            left++;
        }
        else
        {
            count = count + (mid - left + 1);
            right++;
        }
    }
    return count;
}

void mergeSort(vector<int> &arr, int low, int high, int &count)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid, count);      // left half
    mergeSort(arr, mid + 1, high, count); // right half
    counting(arr, low, high, mid, count);

    merge(arr, low, mid, high); // merging sorted halves
}

int inversionCount(vector<int> nums, int n)
{
    int count = 0;
    int low = 0;
    int high = n - 1;
    mergeSort(nums, low, high, count);
    return count;
}

int merge2(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count = count + (mid - left + 1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int mergeSort2(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count = count + mergeSort2(arr, low, mid);      // left half
    count = count + mergeSort2(arr, mid + 1, high); // right half
    count = count + merge2(arr, low, mid, high);    // merging sorted halves
    return count;
}

long long inversionCount(long long arr[], long long N)
{
    // Your Code
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        a[i] = arr[i];
    }
    int ans = mergeSort2(a, 0, N - 1);
    return ans;
}

vector<int> findTwoElement(vector<int> arr, int n)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int num;
    map<int, int>::iterator it = m.begin();
    for (it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second == 2)
            num = ((*it).first);
    }

    sort(arr.begin(), arr.end());

    int ans;

    int i = 0;
    for (it = m.begin(); it != m.end(); it++)
    {
        if ((*it).first != i + 1)
        {
            ans = i + 1;

            goto label;
        }
        i++;
    }
label:;
    vector<int> v;
    v.push_back(num);
    v.push_back(ans);

    return v;
}

int maxLen(vector<int> &a, int n)
{
    // Your code here
    int maxi = 0;
    int sum = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (m.find(sum) != m.end())
            {
                maxi = max(maxi, i - m[sum]);
            }
            else
                m[sum] = i;
        }
    }
    return maxi;
}

int search(vector<int> &nums, int target)
{

    int n = nums.size();
    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
            end = mid - 1;

        if (nums[mid] < target)
            start = mid + 1;

        mid = start + (end - start) / 2;
    }
    return -1;
}

int searchFirst(vector<int> &nums, int target)
{

    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int ans;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }

        if (nums[mid] > target)
            end = mid - 1;

        if (nums[mid] < target)
            start = mid + 1;

        mid = start + (end - start) / 2;
    }
    return ans;
}

int pivot(vector<int> &arr)
{
    int n = arr.size();

    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2; //(start + end)/2;

    while (start < end)
    {

        if (arr[mid] >= arr[0])
            start = mid + 1;

        else
            end = mid;

        mid = start + (end - start) / 2;
    }
    return start;
}

int peakElement(vector<int> nums)
{
    int n = nums.size();
    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (nums[mid] < nums[mid + 1])
            start = mid + 1;
        else
            end = mid;

        mid = start + (end - start) / 2;
    }
    return start;
}

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];
        // we are in left
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
            low = mid + 1;
        // we are on right
        else
            high = mid - 1;
    }
    return -1;
}

int firstOccurence(vector<int> &arr, int n, int key)
{
    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2; //(start + end)/2;

    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        if (key > arr[mid])
            start = mid + 1;

        if (key < arr[mid])
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return ans;
}

int pivoted(vector<int> &arr)
{
    int n = arr.size();

    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2; //(start + end)/2;

    while (start < end)
    {

        if (arr[mid] >= arr[0])
            start = mid + 1;

        else
            end = mid;

        mid = start + (end - start) / 2;
    }
    return start;
}

int BinarySearch2(vector<int> arr, int start, int end, int key)
{
    // int start = 0;
    // int end = n - 1;

    int mid = start + (end - start) / 2; //(start + end)/2;

    while (start <= end)
    {
        if (arr[mid] == key)
            return mid;

        if (key > arr[mid])
            start = mid + 1;

        if (key < arr[mid])
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return -1;
}

// int Search2(int N, vector<int> &A, int key)
// {
//     // Code here
//     int n = N;
//     int pivot = pivoted(A);
//     cout<<"pivot: "<<pivot<<endl;
//     // int first = firstOccurence(A, n, A[pivot]);
//     // cout<<"first: "<<first<<endl;

//     if (key >= A[first] && key <= A[n - 1])
//     { // BS in first line
//         return BinarySearch2(A, first, n - 1, key);
//     }
//     else // BS in second line
//         return BinarySearch2(A, 0, first - 1, key);
// }
int calculateTotalHours(vector<int> &v, int hourly)
{
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {

        // totalH += ceil((double)v[i] / (double)hourly);
        // cout<<v[i]<<" "<<hourly<<endl;
        int one = (int)v[i] / hourly;
        long double two = (long double)v[i] / hourly;
        cout << one << " " << two << endl;
        if (one == two)
            totalH = totalH + one;
        else
            totalH = totalH + one + 1;
    }
    return totalH;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1, high = *max_element(piles.begin(), piles.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int totalH = calculateTotalHours(piles, mid);
        if (totalH <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

bool possible(vector<int> &arr, int day, int m, int k)
{
    int cnt = 0;
    int noOfB = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
            cnt++;

        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    long long val = m * 1LL * k * 1LL;
    if (val > bloomDay.size())
        return -1;
    int low = *min_element(bloomDay.begin(), bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(bloomDay, mid, m, k))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int sumByD(vector<int> &arr, int div)
{
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum = sum + ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    if (nums.size() > threshold)
        return -1;

    int low = 1, high = *max_element(nums.begin(), nums.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (sumByD(nums, mid) <= threshold)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return k + high + 1;
}

bool isPossible(vector<int> a, int n, int cows, int minDist)
{
    int cntCows = 1;
    int lastPlacedCow = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - lastPlacedCow >= minDist)
        {
            cntCows++;
            lastPlacedCow = a[i];
        }
    }
    if (cntCows >= cows)
        return true;
    return false;
}

int AggeresiveCows(int n, int cows, vector<int> &a)
{

    sort(a.begin(), a.end());

    int low = 1, high = a[n - 1] - a[0];

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isPossible(a, n, cows, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

bool BalancedParanthesis(string str)
{
    queue<char> q;
    stack<char> s;
    int x;

    for (int i = 0; i < str.length(); i++)
        q.push(str[i]);

    while (!q.empty())
    {
        char x = q.front();

        if (s.empty() && (x == '{' || x == '(' || x == '['))
        {
            s.push(x);
            q.pop();
            // cout<<"1"<<endl;
        }
        else if (!s.empty() && (x == '{' || x == '(' || x == '['))
        {
            s.push(x);
            q.pop();
            // cout<<"2"<<endl;

        }
        else if (!s.empty() && (x == '}' || x == ')' || x == '}'))
        {
            if ((x =='}' && s.top()=='{') || (x ==')' && s.top()=='(') || (x ==']' && s.top()=='['))
            {
                s.pop();
                q.pop();
            // cout<<"3"<<endl;

            }
            else
            {
            // cout<<"4"<<endl;

                return false;
            }
        }
        else if (s.empty() && (x == '}' || x == ')' || x == '}'))
        {

            // cout<<"5"<<endl;

            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int h;
    cin >> h;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // cout << calculateTotalHours(nums, h) << endl;
    // cout<<1000000000/500000000<<endl;

    // cout << check(nums) << endl;
    // cout << removeDuplicates(nums) << endl;
    // rotate(nums, 3);
    // moveZeroes(nums);
    // cout << missingNumber2(nums) << endl;
    // cout << findMaxConsecutiveOnes(nums) << endl;
    // lenOfLongSubarr(nums);
    // int target;
    // cin>>target;
    // twoSum(nums, target);
    // printVec(twoSum(nums, target));
    // sortColors(nums);
    // cout << majorityElement(nums) << endl;
    // rearrangeArray(nums);
    // nextPermutation(nums);
    // cout << longestConsecutive(nums) << endl;
    // generate(n);
    // vector<vector<int>> nums;
    // int row, col;
    // cin >> row;
    // cin >> col;
    // for (int i = 0; i < row; i++)
    // {

    //     vector<int> temp;
    //     int x, y;
    //     cin >> x >> y;
    //     temp.push_back(x);
    //     temp.push_back(y);
    //     nums.push_back(temp);
    // }
    // merge(nums);
    // int n, m;
    // cin >> m >> n;
    // vector<int> nums1(m);
    // vector<int> nums2(n);
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> nums1[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums2[i];
    // }

    // merge2(nums1, m, nums2, n);

    // int n;
    // cin >> n;
    // vector<int> nums(n);
    // int key;
    // cin >> key;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }

    // cout << maxProduct(nums) << endl;
    // cout<<"Answer is: "<<counting(nums,0,n-1,2)<<endl;
    // cout << inversionCount(nums, n) << endl;
    // findTwoElement(nums, n);
    // sort(nums.begin(), nums.end());
    // printVec(nums);
    // cout << pivot(nums) << endl;
    // cout<<Search2(n,nums,key)<<endl;
    // cout << firstOccurence(nums, n, key) << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    for (int l = 0; l < t; l++)
    {
        // solve();
        string str="()";
        cout<<BalancedParanthesis(str)<<endl;
    }
    return 0;
}