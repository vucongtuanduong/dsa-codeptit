#include <bits/stdc++.h>
using namespace std;
int MAX = 1e6;
vector<long long> prime(MAX + 1, 0);
vector<long long> primeNum;
void init() {
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i] == 0) {
            for (int j = i + i; j <= MAX; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (prime[i] == 0) {
            primeNum.push_back(i);
        }
    }
}
bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
    return a.first > b.first;
}
void testCase() {
    int n;
    cin>>n;
    int a[n];
    for(int &x:a){
        cin>>x;
        
    }
    // for (int x : a) {
    //     cout << x << " ";
    // }
    // cout << endl;
    vector<pair<int, vector<int>>> v;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                // cout << j << endl;
                mp[j].push_back(x);
                mp[x / j].push_back(x);
                
            }
        }
    }
    for (auto x : mp) {
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto x : v) {
        if (x.second.size() >= 2) {
            cout << x.first;
            return;
        }
    }
    // vector<int> sang(1e6+1,0);
    // for(int i=0;i<n;i++){
    //     int x=a[i];
    //     for(int j=1;j<=sqrt(x);j++){
    //         if(x%j==0){
            
    //             sang[j]++;
    //             if(x/j!=j)sang[x/j]++;
    //             lon=max({lon,i,x/j});
            
    //         }
    //     }
    // }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
