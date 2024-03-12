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
    int x,y,z;
    cin >> x >> y >> z;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int dp[x + 1][y + 1][z + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            for (int k = 1; k <= z; k++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1])));
                }
            }
        }
    }
    cout << dp[x][y][z];
}