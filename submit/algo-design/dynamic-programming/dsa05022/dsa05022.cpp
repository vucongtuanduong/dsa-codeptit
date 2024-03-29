#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = x;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = min(dp[i], min(dp[i - 1] + x, dp[i / 2] + z));
        } else {
            dp[i] = min(dp[i], min(dp[i - 1] + x, dp[i / 2 + 1] + z + y));
        }
    }
    cout << dp[n];
}