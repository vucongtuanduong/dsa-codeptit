#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int c, n;
    cin >> c >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dp[c + 1] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = c; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }

    }
    cout << dp[c];
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
