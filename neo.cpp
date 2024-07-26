#include <bits/stdc++.h>
using namespace std;

int lowest(int n)
{
	int res = 0;
    for (int i = n; i >= 1; i--) {
        // If i is a power of 2
        if ((i & (i - 1)) == 0) {
            res = i;
            break;
        }
    }
    return res;


}

int diff(int n, int count)
{

	int c = lowest(n);
	if (n - c == 0)
	{
		return count;
	}
	count++;
	if (n - c != 1 || n - c != 2)
	{
		diff(n - c, count);
		// count++;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int l = 0; l < t; l++)
	{
		int n;
		cin >> n;
		cout << diff(n, 0) << endl;
	}
	// int c;
	// cin>>c;

	// cout << lowest(c);

	return 0;
}
