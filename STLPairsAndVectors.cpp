#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int> &v)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        // v.size -> 0(1)
        cout << v[i] << " ";
    }
    // v.push_back(2);   //we did this change here and we also put & operator before v
    cout << endl;
}

void printvecstring(vector<string> &v)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        // v.size -> 0(1)
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // PAIRS

    // pair<int,string> p;
    // p=make_pair(2,"abc");
    // p={2,"abcd"};
    // cout<<p.first<<" "<<p.second<<endl;

    // pair<int,string> p1=p;
    // p1.first=3;
    // cout<<p.first<<" "<<p.second<<endl;

    // pair<int,string> &p1=p;
    // p1.first=3;
    // cout<<p.first<<" "<<p.second<<endl;

    // int a[]={1,2,3};
    // int b[]={2,3,4};
    // pair<int,int> p_array[3];
    // p_array[0]={1,2};
    // p_array[1]={2,3};
    // p_array[2]={3,4};
    // for (int i = 0; i < 3; i++)
    // {
    //     cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    // }
    // swap(p_array[0],p_array[2]);
    // for (int i = 0; i < 3; i++)
    // {
    //     cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    // }

    // pair<int,string> p;
    // cin>>p.first;
    // cout<<p.first<<endl;

    // VECTORS

    // vector<int> v;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     // printvec(v);
    //     v.push_back(x);
    //     // cin>>v[i];   not vallid
    // }
    // printvec(v);

    // vector<int> v(10,3);
    // v.push_back(7);
    // printvec(v);

    // vector<int> v;
    // v.push_back(7);   //o(1)
    // v.push_back(6);
    // v.push_back(5);
    // printvec(v);
    // v.pop_back();     //o(1)
    // printvec(v);

    // vector<int> v;
    // v.push_back(7);
    // v.push_back(6);
    // vector<int> v2=v;   //o(n)
    // v2.push_back(5);
    // printvec(v);
    // printvec(v2);

    // if we add 2 in the function without & operator then we didnt get the change in the original vector but if we did with & operator then the real value is changed
    // ex - see the change in function

    // vector<int> v;
    // v.push_back(7);
    // v.push_back(6);
    // // printvec(v);
    // // printvec(v);  //run without putting the &  operator in function

    // printvec(v);
    // printvec(v);   //run after putting the & operator

    //  vector<int> v;
    // v.push_back(7);
    // v.push_back(6);
    // vector<int> &v2=v;   //o(n)   putting & here
    // v2.push_back(5);
    // printvec(v);
    // printvec(v);
    // printvec(v2);

    // vector<string> v;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     v.push_back(s);
    // }
    // printvecstring(v);

    // vector<int> v;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     v.push_back(x);
    // }
    // printvec(v);

    // vector<int>::iterator it=v.begin();
    // cout<<*it<<endl;
    // it++;
    // cout<<*it<<endl;

    // vector<pair<int, int>> v;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     v.push_back({x, y});
    // }
    // vector<pair<int, int>>::iterator it = v.begin();
    // cout << (*it).first << " " << (*it).second;

    // for (it = v.begin(); it != v.end(); it++)
    // {
    //     cout << (*it).first << " " << (*it).second;
    // }

    // vector<int> v={11,22,33,44,55};
    // for(auto value: v)
    // {
    //     cout<<value<<" ";
    // }
    // cout<<endl;

    // vector<pair<int,int>>v={{11,22},{33,44},{55,66}};
    // for(auto value: v)
    // {
    //     cout<<value.first<<" "<<value.second<<endl;
    // }

    map<int,string> m;
    m[1]="Khuhal";
    m[5]="Dev";
    m[3]="Shashank";

    for(auto val:m)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }


    return 0;
}
