#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--)
	{
	
		long long n,s,k;
		cin>>n>>s>>k;
		long long sum=0;
		long long a[n+1];
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i<=s)
			{
				sum+=a[i];
			}
		}
		if(sum<=k)
		{
			cout<<1<<endl;
			continue;
		}
		bool ok=true;
		for(long long i=1;i<s;i++)
		{
			if(sum-a[i]<=k)
			{
				cout<<i+1<<endl;
				ok=false;
				break;
			}
			else
			{
				sum-=a[i];
			}
		}
		if(ok)
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}