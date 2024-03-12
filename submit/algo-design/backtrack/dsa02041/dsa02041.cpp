#include <bits/stdc++.h>
using namespace std;
void testCase();
int maxSteps(int n );
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
int maxSteps(int n ) {
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        } 
        if (i % 3 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 3]);
        }
        dp[i] = min(dp[i], 1 + dp[i - 1]);
    }
    return dp[n];
}
void testCase() {
    int n;
    cin >> n;
    cout << maxSteps(n);
}