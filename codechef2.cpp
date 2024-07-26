#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int t;
    cin >> t;
    for (int l = 0; l < t; l++)
    {
        int n;
        cin >> n;
        int fog = 1;
        int i = 2;
        while ((i * i) <= n)
        {
            if (n % i == 0 && (i != (n / i)))
            {
                fog = 0;
                break;
            }
            i++;
        }
        if (fog == 1)
            cout << -1 << endl;
        else
            cout << i << " " << 1 << " " << n / i << endl;


    }


    return 0;
}
