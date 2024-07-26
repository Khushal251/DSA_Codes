#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main(int argc, char const *argv[])
{
    set<int> myemptyset;

    myemptyset.insert(10);
    myemptyset.insert(100);
    myemptyset.insert(1000);
    myemptyset.insert(10000);



    set<int> mynewset (myemptyset);

    mynewset.erase(10);

    set<int>::iterator it;
    for(it=mynewset.begin(); it!=mynewset.end(); ++it)
    cout<<' '<< *it;
    cout<<'\n';

    return 0;
}
