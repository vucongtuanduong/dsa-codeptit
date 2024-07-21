#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    int n,c;
	cin>>n>>c;
	long long a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	long long dp[n+1]={};
	dp[2]=c+(a[2]-a[1])*(a[2]-a[1]);
	for(int i=3;i<=n;i++){
        for (int j = i + 1; j <= n; j++) {
            
        }
		dp[i]=min(dp[i-1]+(a[i]-a[i-1])*((a[i]-a[i-1]))+c,dp[i-2]+((a[i]-a[i-2])*(a[i]-a[i-2]))+c);
	}
//	for(long long x:dp)cout<<x<<" ";
	cout<<dp[n];
    return 0;
}
