#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    int x, y , z;
    cin >> x >> y >> z;
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = x;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = min({dp[i], dp[i - 1] + x, dp[i / 2] + z});
        } else {
            dp[i] = min({dp[i], dp[i - 1] + x, dp[i / 2 + 1] + y + z});
        }
        
    }
    cout << dp[n];
}
int main() {
    
    // Write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
