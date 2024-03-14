#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, s;
    while (cin >> n >> k >> s, n || k || s) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(s+1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
                for (int l = 0; l <= s; l++) {
                    dp[i][j][l] = dp[i-1][j][l];
                    if (j >= 1 && l >= i)
                        dp[i][j][l] += dp[i-1][j-1][l-i];
                }
        cout << dp[n][k][s] << endl;
    }
    return 0;
}