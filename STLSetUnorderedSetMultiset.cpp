#include <bits/stdc++.h>
using namespace std;

void print(set<string> &s)
{
    for(string value : s)
    {
        cout<<value<<endl;   
    }
    // for(auto it=s.begin();it!=s.end();it++)
    // {
    //     cout<<(*it)<<endl;
    // }
}
void printmulti(multiset<string> &s)
{
    for(string value : s)
    {
        cout<<value<<endl;   
    }
    // for(auto it=s.begin();it!=s.end();it++)
    // {
    //     cout<<(*it)<<endl;
    // }
}

int main()
{
    // set<string> s;
    // s.insert("abc");   // log(n)
    // s.insert("zsdf");
    // s.insert("bcd");
    // s.insert("abc");   //stores only unique value
    // auto it=s.find("abc");   // log(n)
    // if(it!=s.end())
    // {
    //     cout<<(*it)<<endl;
    // }
    // print(s);
    //  if(it!=s.end())
    // {
    //     s.erase(it);
    // }


    // Quesrion = given n strings, print unique strings in lexiographical order
    // set<string> s;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     string str;
    //     cin>>str;
    //     s.insert(str);
    // }
    // for(auto value : s)
    // {
    //     cout<<value<<endl;
    // }


    // UNORDERED SET

    // unordered_set<string> s;
    // s.insert("abc");   // O(1)
    // s.insert("zsdf");
    // s.insert("bcd");
    // s.insert("abc");   //stores only unique value
    // auto it=s.find("abc");   // O(1)
    // if(it!=s.end())
    // {
    //     cout<<(*it)<<endl;
    // }
    // // print(s);
    //  if(it!=s.end())
    // {
    //     s.erase(it);
    // }

    // QUESTION = Given n strings and q quiries in each quary you are given a string print yes if string is present else print no.
    // unordered_set<string> s;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     string str;
    //     cin>>str;
    //     s.insert(str);
    // }
    // int q;
    // cin>>q;
    // for (int i = 0; i < q; i++)
    // {
    //     string str;
    //     cin>>str;
    //     if(s.find(str)==s.end())
    //     {
    //         cout<<"no"<<endl;
    //     }
    //     else
    //     {
    //         cout<<"yes"<<endl;


    //     }
    // }


    // MULTISET

    multiset<string> s;
    s.insert("abc");   // o(log(n))
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");   //stores only unique value
    // printmulti(s);
    auto it=s.find("abc");   // o(log(n))
     if(it!=s.end())
    {
        s.erase(it);
    }

    s.erase("abc");   // all abc got deleted
    printmulti(s);


    
    




    

   



    return 0;
}
