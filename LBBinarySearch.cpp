#include <bits/stdc++.h>
using namespace std;
#define int long long int

int BinarySearch(vector<int> arr, int n, int key)
{
    int start = 0;
    int end = n - 1;

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

int func(vector<int> &arr, int start, int end, int key)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return mid;

    else if (arr[mid] > key)
        return func(arr, start, mid - 1, key);

    else 
        return func(arr, mid + 1, end, key);
}


int BinarySearchRecursion(vector<int> arr, int n, int key)
{
    int ans = func(arr, 0, n - 1, key);

    if (ans == -1)
        cout << "Target dosnt exist in this array" << endl;
    else
        cout << "Target is present at the index: " << ans << endl;
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

pair<int, int> firstAndLastOccurance(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2; //(start + end)/2;

    pair<int, int> ans;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans.first = mid;
            end = mid - 1;
        }

        if (key > arr[mid])
            start = mid + 1;

        if (key < arr[mid])
            end = mid - 1;

        mid = start + (end - start) / 2;
    }

    start = 0;
    end = n - 1;

    mid = start + (end - start) / 2; //(start + end)/2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans.second = mid;
            start = mid + 1;
        }

        if (key > arr[mid])
            start = mid + 1;

        if (key < arr[mid])
            end = mid - 1;

        mid = start + (end - start) / 2;
    }

    return ans;

    // To find the total number of occurence = last occurence + first occurence +1;
}

int peakIndexInMountainArray(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    int mid = start + (end - start) / 2; //(start + end)/2;

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
            start = mid + 1;

        else
            end = mid;

        mid = start + (end - start) / 2;
    }
    return start;
}

int getPivot(vector<int> arr, int n)
{
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

int findPosition(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
    { // BS in first line
        return BinarySearch2(arr, pivot, n - 1, k);
    }
    else // BS in second line
        return BinarySearch2(arr, 0, pivot - 1, k);
}

int mySqrtFunc(int n)
{
    int s=0;
    int e=n;
    int mid = s+(e-s)/2;

    int ans=-1;
    while(s<=e)
    {
        int square=mid*mid;

        if(square==n)
        return mid;

        if(square<n)
        s=mid+1;

        else
        e=mid-1;

        mid= s+(e-s)/2;
    }
    return ans;

}

double morePrecision(int n,int precision, int tempSol)
{
    double factor=1;
    double ans=tempSol;

    for (int i = 0; i < precision; i++)
    {
        factor=factor/10;

        for (double j = ans; j*j < n; j=j+factor)
        {
            ans=j;
        }
        
    }

    return ans;
    
}

double mySqrt(int n)
{
    int tempSol= mySqrtFunc(n);
    return morePrecision(n,3,tempSol);

}

int32_t main()
{
    // int arr[] = {1, 2, 5, 7, 13, 22, 54};
    vector<int> v = {1, 2, 5, 7, 13, 22, 54};
    // int a = BinarySearch(arr, 7, 56);
    // cout << a << endl;
    // cout << firstAndLastOccurance(arr, 7, 3).first << " " << firstAndLastOccurance(arr, 7, 3).second << endl;
    // BinarySearchRecursion(v, 7, 12);
    cout<<mySqrt(37)<<endl;
    return 0;
}
