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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(k, -1);
    dp[0] = 0;
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        vector<int> dpNext = dp;
        for (int j = 0; j < k; j++) {
            if (dp[j] != -1) {
                dpNext[(j + a[i]) % k] = max(dpNext[(j + a[i]) % k], dp[j] + 1);
            }   
        }
        dp = dpNext;
        maxLength = max(maxLength, dp[0]);
    }
    cout << maxLength;
}