#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i - k; j < i; j++) {
            if (j >= 0) {
                dp[i] = dp[i] + dp[j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n];
}
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
