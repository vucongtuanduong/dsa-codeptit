#include <bits/stdc++.h>
using namespace std;
void testCase();
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
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    int dp[n + 1] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++ ) {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[n];
}