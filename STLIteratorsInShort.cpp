#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v ={2,3,4,5,6,7};
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it = v.begin();
    for ( it = v.begin(); it != v.end(); it++)
    {
        cout<<(*it)<<' ';
    }
    cout<<endl;

    for (int &value : v)
    {
        value++;
    }

    for (int value : v)
    {
        cout<<value<<" ";
    }

    // vector<pair<int,int>>v_p={{1,2},{2,3},{3,4}}
    // for (pair)
    // {
    //     /* code */
    // }
    
    
    return 0;
}
