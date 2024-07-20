#include <bits/stdc++.h>
using namespace std;
void testCase() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << "1";
        return;
    }
    vector<long long> v;
    for (int i = 9; i >= 2; i--) {
        while (n % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        cout << "-1";
        return;
    }
    sort(v.begin(), v.end());
    long long res = 0;
    for (long long x : v) {
        res = res * 10 + x;
    }
    cout << res;
}
void testCase2() {
    long long n;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return ;
    }
    vector<int> v;
    for(int i=9;i>=2;i--)
    {
        while(n%i==0)
        {
            v.push_back(i);
            n/=i;
        }
    }
        if(n!=1)
        {
        cout<<-1;
        return ;
        } 
        sort(v.begin(),v.end());
        long long  res=0;
        for(auto x:v)
        {
        res=(long long )res*10+x;
        }
        cout<<res;
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
