#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // vector<int> v ={2,3,4,5,6,7};
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // vector<int>::iterator it = v.begin();
    // for ( it = v.begin(); it != v.end(); it++)
    // {
    //     cout<<(*it)<<endl;
    // }


    // Iterators point to pairs

    vector<pair<int,int>> v_p = {{1,2},{2,3},{3,4}};
    vector<pair<int,int>> :: iterator it;
    // for (it = v_p.begin(); it != v_p.end(); it++)
    // {
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }

    //    Or we can also use
    
    for (it = v_p.begin(); it != v_p.end(); it++)
    {
        cout<<(it->first)<<" "<<(it->second)<<endl;
    }
    

    
    
    
    return 0;
}
