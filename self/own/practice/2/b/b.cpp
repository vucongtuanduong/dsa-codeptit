#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    int n = s.length();
    int a[n] = {0};
    int b[n] = {0};
    map<char,int>mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    int lim = mp.size();
    mp.clear();
    for (int i = 0; i < n; i++ ) {

    }
    
    for (int i = n - 1; i >= 0; i--) {
        mp[s[i]]++;
        b[i] = mp.size();
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
}
void testCase2(){ 
    string s;
	cin>>s;
	set<char> se;
	for(auto x:s)
	{
		se.insert(x);
	}
	int lim=se.size();
	int n=s.size();
	se.clear();
	int l[n];
	l[0]=1;
	se.insert(s[0]);
	int i1=0;
	int m1=0;
	map<char,int>mp;
	mp.insert({s[0],0});
	for(int i=1;i<n;i++)
	{
		if(se.find(s[i])==se.end())
		{
			l[i]=l[i-1]+1;
			se.insert(s[i]);
			mp.insert({s[i],i});
		}
		else
		{	
			mp[s[i]]=i;
			l[i]=l[i-1];
		}
		if(l[i]==1)
		{
			i1=i;
		}
		if(l[i]==lim)
		{
			m1=i-i1+1;
			break;
		}
	}
	int lon1=0,nho1=lim;
	for(auto x:mp){
		if(lon1<x.second)lon1=x.second;
		if(nho1>=x.second)nho1=x.second;
	}
	
	reverse(s.begin(),s.end());
	se.clear();
	int r[n];
	r[0]=1;
	se.insert(s[0]);
	int i2=0;
	int m2=0;
	map<char,int>mp1;
	mp1.insert({s[0],0});
	for(int i=1;i<n;i++)
	{
		if(se.find(s[i])==se.end())
		{
			r[i]=r[i-1]+1;
			se.insert(s[i]);
			mp1.insert({s[i],i});
		}
		else
		{	
			mp1[s[i]]=i;
			r[i]=r[i-1];
		}
		if(r[i]==1)
		{
			i2=i;
		}
		if(r[i]==lim)
		{
			m2=i-i2+1;
			break;
		}
	}
	int lon2=0,nho2=lim;
	for(auto x:mp1){
		if(lon2<x.second)lon2=x.second;
		if(nho2>=x.second)nho2=x.second;
	}
	cout<<min({m1,m2,lon1-nho1+1,lon2-nho2+1});
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase2();
        cout << endl;
    }
    return 0;
}