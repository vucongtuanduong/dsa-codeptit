#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string a, b;
    cin >> a >> b;
    // cout << a << " " << b << endl;
    int n = a.size();
    int m = b.size();
    int res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ;j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            // res = max(res, dp[i][j]);
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
