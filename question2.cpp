#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int* place(int arr[],int ind)
{
    for (int i = ind; i >=2 ; i++)
    {
        arr[i]=arr[i-1];
    }
    arr[1]=arr[ind];
    
    return arr;
    

}

int main(int argc, char const *argv[])
{
    int n,q,k=1;
    cin>>n>>q;
    int a[n];
    int Q[q];
    
    int res[q];
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin>>Q[i];
    }

    for (int j = 1; j <= q; j++)
    {
        int ind=0;
        for (int i = 1; i <= n; i++)
        {                                                    
            int c=0;
            if(Q[j]==a[i])
            {
                ind=i;
                res[k]=i;
                k++;
                for (int i = ind; i >=2 ; i--)
                {
                    c=a[ind];
                    a[i]=a[i-1];
                }
                a[1]=c;
                break;
            }
        }
        
    }

    for (int i = 1; i <=q ; i++)    
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}
