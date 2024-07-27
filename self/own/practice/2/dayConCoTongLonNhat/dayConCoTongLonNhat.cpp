#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = max(dp[i - 1], dp[i - 1] + a[i]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }

}
int main() {
    // Write your code here
    testCase();
    return 0;
}
