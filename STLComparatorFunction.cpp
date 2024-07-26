#include <bits/stdc++.h>
using namespace std;

bool should_i_swap(int a,int b)
{
    // if(a<b)
    // {
    //     return true;
    // }
    // return false;

    // or

    return a>b;
}

bool should_i_swap_2(pair<int,int>a,pair<int,int>b)
{
    // if(a.first!=b.first)
    // {
    //     if(a.first>b.first)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
    // else
    
    // {
    //     if(a.first<b.second)
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    // or

    if(a.first!=b.first)
    {
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if(should_i_swap(arr[i],arr[j]))
    //         {
    //             swap(arr[i],arr[j]);
    //         }
    //     }
        
    // }
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    // int n;
    // cin>>n;
    // vector<pair<int,int>>arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i].first>>arr[i].second;
    // }
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if(should_i_swap_2(arr[i],arr[j]))   //or we can use greater<pair<int,int>>() as a comparetor
    //         {
    //             swap(arr[i],arr[j]);
    //         }
    //     }
        
    // }

    // sort(arr.begin(),arr.end(),should_i_swap_2);


    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
    // }
    // cout<<endl;
    


    return 0;
}
