#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
}
int main() {
    // Write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
