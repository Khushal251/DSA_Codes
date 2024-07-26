#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int l = 0; l < t; l++)
	{
		int n, x;
		cin >> n >> x;
		int arr[n];
		int gg;
		for (int i = 0; i < n; i++)
		{
			arr[i] = i + 1;
		}
		int f[n];
		int count = 0;
		int res[n];

		sort(arr, arr + n);

		// cout << "The n! possible permutations with n elements:\n";
		do
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
			
				f[0] = arr[0];
				for (int j = 1; j < n; j++)
				{
					f[i] = __gcd(f[i - 1], arr[i]);
					cout<<f[i]<<" ";
				}
				for (int i = 0; i < n; i++)
				{
					sum = sum + f[i];
					// cout << "the sum is" << sum << endl;
				}
			}
			if (sum == x)
			{
				count++;
				for (int i = 0; i < n; i++)
				{
					cout << arr[i] << " ";
				}
				cout << endl;
				break;
			}
			
		} while (next_permutation(arr, arr + n));

		if (count == 0)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
