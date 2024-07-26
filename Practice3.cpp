#include <bits/stdc++.h>
using namespace std;
#define int long long int

int equalCandies(vector<int> &candies, int n)
{
    // Write your code here.
    int num = 0;
    for (int i = 0; i < candies.size(); i++)
    {
        num =num+candies[i];
    }

    int avg=num/n;

    int ans=0;

    for (int i = 0; i < candies.size(); i++)
    {
        ans=ans+ abs(candies[i]-avg);
        
    }
    return ans;
    
}

int32_t main()
{

    int n;
    cin >> n;
    vector<int> v(n);

    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    sum1 = v[n - 1];
    sum2 = v[n - 2];
    int j = n - 3;
    while (j >= 0)
    {
        if (abs(sum1 + v[j] - sum2) <= abs(sum2 + v[j] - sum1))
        {
            sum1 = sum1 + v[j];
            j--;
        }
        else
        {
            sum2 = sum2 + v[j];
            j--;
        }
    }

    cout << abs(sum1 - sum2) << endl;

    return 0;
}
