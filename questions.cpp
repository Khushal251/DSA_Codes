#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int l=0;l<t;l++)
	{
	    int n,k,sum=0,x;
	    cin>>n>>k;
	    int a[n][n];
	    
	    for(int i=1;i<=n;i++)
	    {
            for (int j = 1; j <= n; j++)
            {
	            a[i][j]=i+n*(j-1);
                
            }
            
	    }
	    int j=1;
        for(int i = 1; i <=n-1; i++)
        {
            sum=sum+a[i][j]+a[i][j+1];
            j++;
            
        }
        sum=sum+a[n][n];
        cout<<sum<<endl;
        
        x=sum%2;
        if(x==k)
        {
            cout<<"YES"<<endl;
        }
        else if(x!=k)
        {
            cout<<"NO"<<endl;
        }

    
	    
	}
	return 0;
}