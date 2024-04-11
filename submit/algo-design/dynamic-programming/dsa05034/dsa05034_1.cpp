#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    int dp[n + 1] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i]  = (dp[i] + dp[i - j] ) % MOD;
            }
        }
    }
    cout << dp[n];
}