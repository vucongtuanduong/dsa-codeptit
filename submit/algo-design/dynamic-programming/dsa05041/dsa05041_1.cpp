#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    s = " " + s; // Add a space at the beginning, not a zero
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    int res = 1;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max({dp[i + 1][j], dp[i][j - 1]});
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << n - 1 - res; // Subtract 1 because we added a space at the beginning
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}