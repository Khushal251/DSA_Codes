#include <bits/stdc++.h>
using namespace std;
#define int long long int

void printVec(vector<int> v)
{
	cout << "size : " << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int solve()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}

	sort(v.begin(),v.end());


	int ans=LLONG_MAX;
	int count;

	for (int i = 1; i < v.size(); i++)
	{
		count=v[i]-v[i-1];
		ans=min(ans,count);
	}
	return ans;
}



int32_t main()
{
	int t;
	cin >> t;
	for (int l = 0; l < t; l++)
	{
		cout << solve() << endl;
	}
	return 0;
}