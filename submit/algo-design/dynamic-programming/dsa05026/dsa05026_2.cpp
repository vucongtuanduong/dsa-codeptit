#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int c, n;
    cin >> c >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
       cin >> a[i];
    }
    // sort(a, a + n, greater<int>());
    vector<int> dp(c + 1, 0);
    int res = 0;
    for (int i = 1; i <= n; i++ ){
        for (int j = c; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    cout << dp[c];
}