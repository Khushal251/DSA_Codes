#include <bits/stdc++.h>
using namespace std;
#define int long long int
void printvec(vector<int> v)
{
    cout << "Size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    for (int h = 0; h < t; h++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
        {
            if (a - b > c)
                cout << "First" << endl;
                if((a-b)==c)
                    cout << "Second" << endl;


            if (a - b < c)
            {
                if ((c - (a - b)) % 2 == 0)
                    cout << "Second" << endl;
                else
                    cout << "First" << endl;
            }
        }
        if (a < b)
        {
            if (b - a >= c)
                cout << "Second" << endl;
            if (b - a < c)
            {
                if ((c - (b - a)) % 2 == 0)
                    cout << "Second" << endl;
                else
                    cout << "First" << endl;
            }
        }
        if (a - b == 0)
        {
            if (c % 2 == 0)
                cout << "Second" << endl;
            else
                cout << "first" << endl;
        }
    }
    return 0;
}