#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{

	// vector <int> v={10,20,30,40,50};
	// vector<int> :: iterator it=v.begin();
	// // for (it=v.begin(); it!=v.end();it++)
	// // {
	// // 	cout<<*(it)<<" ";
		
	// // }
	// cout<<*(it+2);
	// cout<<endl;
	
	// vector<pair<int,int>> v={{2,3},{4,5},{7,9}};
	// vector<pair<int,int>> :: iterator it;
	// for (it=v.begin();it!=v.end();it++)
	// {
	// 	cout<<(*(it)).first<<" "<<(*(it)).second<<endl;
	// }

	// for(auto value: v)
	// {
	// 	cout<<value.first<<" "<<value.second<<endl;
	// }

	set<int> s;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		s.insert(x);
	}
	cout<<"output is"<<endl;

	set<int> :: iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*(it)<<" ";
	}
	cout<<endl;
	auto le=s.find(5);
	s.erase(le);
	cout<<"new list is"<<endl;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*(it)<<" ";
	}
	cout<<endl;
	
	


	



	return 0;
}