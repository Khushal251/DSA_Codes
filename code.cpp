#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int l = 0; l < t; l++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i+1])
            {
                cout << i + 1 << " " << i + 2 << " " << endl;
               
            }
        }
        cout << -1 << " " << -1 << endl;
    }
    return 0;
}
// regex