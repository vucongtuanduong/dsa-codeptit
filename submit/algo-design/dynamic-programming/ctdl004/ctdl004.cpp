#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    

    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < j; k++) {
                if (a[k] < a[j]) {
                    dp[j][i] += dp[k][i - 1];
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dp[i][k];
    }
    cout << sum;
}