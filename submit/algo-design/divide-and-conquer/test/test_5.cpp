#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long countWays(long long n) {
    vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
    for (int i = 0; i < 5; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
        dp[i][4] = (dp[i - 1][0]) % MOD;
    }
    int res = 0;
    for (int j = 0; j < 5; j++) {
        res = (res + dp[n][j]) % MOD;
        res %= MOD;
    }
    return res;
}
int main() {
    // Write your code here
    long long n;
    cin >> n;
    cout << countWays(n);
    return 0;
}
