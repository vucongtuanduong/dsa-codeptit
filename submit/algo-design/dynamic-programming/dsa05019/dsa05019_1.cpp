#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a, dp;
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp.resize(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    for (int i = 1; i <= n; i++){ 
        for (int j = 1; j <= m; j++) {
            if (a[i - 1][j - 1] == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
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
