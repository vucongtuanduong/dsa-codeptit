#include <bits/stdc++.h>
using namespace std;
int maxValue(vector<pair<int,int>> a, int weight) {
    int n = a.size();
    vector<vector<int>>dp(n + 1, vector<int>(weight + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= weight; j++) {
            int inc = 0, exc = 0;//include or exclude
            if (a[i - 1].first <= j) {
                inc =  a[i - 1].second + dp[i - 1][j - a[i - 1].first];
            }
            exc = dp[i - 1][j];

            dp[i][j] = max(inc, exc);
        }
    }
    return dp[n][weight];
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector<pair<int,int>>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;//weight

        }   
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;//value
        }     
        cout << maxValue(a, w) << endl;
    }
    return 0;
}
