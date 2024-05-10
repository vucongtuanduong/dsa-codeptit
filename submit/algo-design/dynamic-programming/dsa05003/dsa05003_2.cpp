#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int a, b, c;
    cin >> a >> b >> c;
    string x, y , z;
    cin >> x >> y >> z;
    int dp[a + 1][b + 1][c + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                if (x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1]) {
                    dp[i][j][k]  = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    cout << dp[a][b][c];
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
