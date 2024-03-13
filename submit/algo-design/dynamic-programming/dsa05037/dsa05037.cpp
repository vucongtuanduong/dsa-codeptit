#include <bits/stdc++.h>
using namespace std;
const int MOD =  1e9 + 7;
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
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(10));
    for (int j = 0; j < 10; j++) {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    int count = 0;
    for (int j = 0; j < 10; j++) {
        count = (count + dp[n][j]) % MOD;
    }
    cout << count;
}