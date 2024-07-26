#include <bits/stdc++.h>
using namespace std;

void print(set<string> v)
{
    cout << v.size() << endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << endl;
    }
}
void permute(string &a, int l, int r, set<string> &v)
{

    if (l == r)
    {
        v.insert(a);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {

            swap(a[l], a[i]);

            permute(a, l + 1, r, v);

            swap(a[l], a[i]);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    set<string> v;

    permute(str, 0, n - 1, v);

    print(v);
    return 0;
}
