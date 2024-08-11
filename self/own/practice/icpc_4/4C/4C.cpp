#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> grid[i];
        grid[i] = " " + grid[i]; // To make the grid 1-indexed
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    long long ans = 0;

    // Initialize the first column
    for (int i = 1; i <= n; ++i) {
        if (grid[i][1] == '#') dp[i][1] = 1;
        ans = max(ans, dp[i][1]);
    }

    // Fill the DP table
    for (int j = 2; j <= m; ++j) {
        for (int i = 2; i <= n - 1; ++i) {
            dp[i][j] = max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]});
            if (grid[i][j] == '#') dp[i][j]++;
            ans = max(dp[i][j], ans);
        }
    }

    cout << m - ans << endl;

    return 0;
}