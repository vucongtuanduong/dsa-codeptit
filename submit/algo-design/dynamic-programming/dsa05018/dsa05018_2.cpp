#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<bool>> dp;
    dp.resize(n, vector<bool>(n, false));
    for (int i = 0; i  < n; i++) {
        dp[i][i] = true;
    }
    int res = 1;
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n - k; i++) {
            int j = i + k;
            if (s[i] == s[j] && k == 1) {
                dp[i][j] = true;
            } else if (s[i] == s[j] && k > 1) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = false;
            }
            if (dp[i][j] == true) {
                res = max(res, j - i + 1);
            }
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
