#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 1, 0);
    int leftMax = 0;
    for (int i = 0; i < n; i++) {
        dp[a[i]] = dp[a[i]  - 1] + 1;
        cout << "dp[a[i]]: " << dp[a[i]] << ", dp[a[i] - 1]: " << dp[a[i] - 1] << endl;
        leftMax = max(leftMax, dp[a[i]]);
    }
    cout << n - leftMax;
}