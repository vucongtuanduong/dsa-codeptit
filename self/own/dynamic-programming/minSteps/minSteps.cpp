 #include <bits/stdc++.h>
using namespace std;
int memo[100];
int dp(int n) {
    if (n == 1) {
        return 0;
    }
    int &ans = memo[n];
    if (ans != -1) {
        return ans;
    }
    ans = INT_MAX;
    if (n % 2 == 0) {
        ans = min(ans, dp(n / 2));
    }
    if (n % 3 == 0) {
        ans = min(ans, dp(n / 3));
    }
    ans = min(ans, dp(n - 1));
    ans ++;
    return ans;
}
int minWays(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }
    return dp[n];
}
int main() {
    // Write your code here
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << dp(n) << endl;
    cout << minWays(n) << endl;
    return 0;
}
