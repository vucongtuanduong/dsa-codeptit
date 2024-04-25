#include <bits/stdc++.h>
using namespace std;
int countWaysTD(int n, int k, long long *dp) {
    if (n == 0) {
        return 1;
    } 

    if (n < 0) {
        return 0;


    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int res = 0;
    for (int jump = 1; jump <= k; jump++) {
        res += countWaysTD(n - jump, k, dp);
    }
    return dp[n] = res;
}
//O(n * k)
int countWaysBU(int n, int k) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

//O(n + k) 
int countWaysOpt(int n, int k) {
    vector<long long> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++) {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }
    return dp[n];
}
void testCase() {
    int n, k;
    cin >> n >> k;
    long long dp[n + 1] = {0};
    // cout << countWaysTD(n, k, dp);
    // cout << countWaysBU(n, k);
    cout << countWaysOpt(n, k);
    

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
