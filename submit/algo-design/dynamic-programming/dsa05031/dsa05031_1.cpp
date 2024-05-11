#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1) ;
        }
    }
    cout << dp[n];

}
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
