#include <bits/stdc++.h>
using namespace std;

// UNORDERED MAPS
// 1. inbuilt implementation 
// 2. time complaxcity
// 3. valid key datatype

void print(unordered_map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    unordered_map<int, string> m;
    m[1] = "abc"; /* o(1) */
    m[5] = "cdc";
    m[3] = "acd";
    // m.insert({4, "afg"});
    m[6]="a";
    m[5]="cde";
  
  
    // map<int,string>:: iterator it;
    // for (it=m.begin(); it !=m.end();it++)
    // {
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }

    // for (auto &pr : m)
    // {
    //     cout<<pr.first<<" "<<pr.second<<endl;
    // }
    print(m);


    return 0;
}


