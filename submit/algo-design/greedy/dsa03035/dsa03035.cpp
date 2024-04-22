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
        // cout << "a[i]: " << a[i] << ", a[i] - 1: " << a[i] - 1 << endl;
        
        dp[a[i]] = dp[a[i]  - 1] + 1;    
        // cout << "dp[a[i]]: " << dp[a[i]] << ", dp[a[i] - 1]: " << dp[a[i] - 1] << endl;
        // cout << "-------------------------\n";
        leftMax = max(leftMax, dp[a[i]]);
    }
    cout << n - leftMax;
}