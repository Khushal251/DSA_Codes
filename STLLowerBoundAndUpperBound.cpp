#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // int*ptr=lower_bound(arr,arr+n,5);
    // if(ptr==(arr+n))
    // {
    //     cout<<"Not Found";
    //     return;
    // }
    int*ptr=upper_bound(arr,arr+n,5);
    if(ptr==(arr+n))
    {
        cout<<"Not Found";
        return;
    }
    cout<<*ptr<<endl;


    return 0;
}
