#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int l = 0; l < t; l++)
	{
		int n, count = 0;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < n - 1; i++)
		{
			if ((arr[i] + arr[i + 1]) % 2 != 0)
			{
				arr[i + 1] = arr[i];
				count++;
			}
		}
		cout<<count<<endl;
	}

	return 0;
}