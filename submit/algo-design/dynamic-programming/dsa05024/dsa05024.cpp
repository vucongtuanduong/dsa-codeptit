#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
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
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= a[j]) {
                dp[i] += dp[i - a[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[k];
}