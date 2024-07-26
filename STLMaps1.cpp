#include <bits/stdc++.h>
using namespace std;


// ORDERED MAPS

void print(map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    // map<int, string> m;
    // m[1] = "abc"; /* o(log(n)) */
    // m[5] = "cdc";
    // m[3] = "acd";
    // m.insert({4, "afg"});
    // m[6];
  
    // // // we can also do
    // // map<string,string> m;
    // // m["abcd"]="abcd";
    // // map<int,string>:: iterator it;
    // // for (it=m.begin(); it !=m.end();it++)
    // // {
    // //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // // }

    // // for (auto &pr : m)
    // // {
    // //     cout<<pr.first<<" "<<pr.second<<endl;
    // // }
    // // m[5]="Khushal";
    // // print(m);

    // // auto it = m.find(3);   /* o(log(n)) */
    // // if(it==m.end())
    // // {
    // //     cout<<"NO VALUE"<<endl;
    // // }
    // // else
    // // {
    // //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // // }

    // // m.erase(3);
    // // print(m);

    // auto it = m.find(5);
    // if (it != m.end())
    // {
    //     m.erase(it);
    // }
    // print(m);



    // Given n strings , print unique strings in lexiographical order with there frequency
    map<string,int> m;
    int n;
    cin>> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
    m[s]++;
    }
    for(auto pr : m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    

    // input
    // 8
    // abc
    // def
    // abc
    // ghj
    // jkl
    // ghj
    // ghj
    // abc

    

    return 0;
}
