#include <bits/stdc++.h>
using namespace std;
#define int long long int

int solve(string s)
{

    if (s[0] == '0')
    {
        // cout << 0 << '\n';
        return 0;
    }
    int count2 = 1,count1=1;
    for (int i = 0; i < s.size(); i++)
    {
        // if (i == 0 && s[i] == '?')
        //     count1 *= 9;
        if (i!=0 &&s[i] == '?')
            count2 *= 10;
    }
    // cout << count << '\n';
    // return count;
    if(s[0]=='?')
    return count2*9;
    else
    return count2;
}

int32_t main()
{
    int t;
    cin >> t;
    for (int h = 0; h < t; h++)
    {
        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
    return 0;
}