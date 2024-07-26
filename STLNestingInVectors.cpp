#include <bits/stdc++.h>
using namespace std;

void printvec(vector<pair<int,int>> &v)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " "<<v[i].second<<endl;
    } 
    cout << endl;
}

void printarrvec(vector<int> &v)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] <<" ";
    } 
    cout << endl;
}



int main()
{
    // NESTING OF VECTORS


    // Vector of pairs

    // vector<pair<int,int>> v={{1,2},{2,3},{3,4}};
    // printvec(v);

    // vector<pair<int,int>> v;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     v.push_back({x,y});
        
    // }
    // printvec(v);


    // Array of Vectors

    // int N;
    // cin>>N;
    // vector<int> v[N];
    // for (int i = 0; i < N; i++)
    // {
    //     int n;
    //     cin>>n;
    //     for (int j = 0; j < n; j++)
    //     {
    //         int x;
    //         cin>>x;
    //         v[i].push_back(x);
    //     }
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     printarrvec(v[i]);
    // }
    // cout<<v[0][0]<<endl;
    // cout<<v[0][1]<<endl;
          
            //  or

    //  int N;
    // cin>>N;
    // vector<int> v[N];
    // for (int i = 0; i < N; i++)
    // {
    //     int n;
    //     cin>>n;
    //     for (int j = 0; j < n; j++)
    //     {
    //         int f;
    //         cin>>f;
    //         v[i].push_back(f);
    //     }
        
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     cout<<"Size : "<<v[i].size()<<endl;
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
        

    // }        


    // Vector of Vector

      int N;
    cin>>N;
    vector<vector<int>> v;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin>>n;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    v[0].push_back(10);
    for (int i = 0; i < v.size(); i++)
    {
        printarrvec(v[i]);
    }
    cout<<v[0][1]<<endl;

        //  or

    vector<vector<int>> v;
    int N;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin>>n;
        vector<int>temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
            
        }
        cout<<endl;
        
    }        

    return 0;
}
