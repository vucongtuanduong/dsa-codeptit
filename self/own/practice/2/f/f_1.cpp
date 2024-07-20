#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void solve()
{
	long long n,s,k;
	cin>>n>>s>>k;
	long long a[n+1]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	if(a[s]<=k)
	{
		cout<<1;
		return ;
	}
	int i=1;
	while(a[s]>k&&i<s)
	{
		a[s]-=a[i];
		i++;
	}
	if(a[s]<=k)
	{
		cout<<i;
		
	}else
	{
		cout<<-1;
	}
}
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--)
	{
		solve();
		cout<<endl;
	}
	return 0;
}