#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a, dp;
    a.resize(n, vector<int>(m));
    for (int i = 0; i< n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp.resize(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        
        for (int j = 1; j <= m; j++) {
            
            dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + a[i - 1][j - 1];
            
        }
    }
    cout << dp[n][m];
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
