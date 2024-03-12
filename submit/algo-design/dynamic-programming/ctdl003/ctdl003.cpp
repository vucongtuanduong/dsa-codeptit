#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void testCase();
void scanArray(int *a, int n);
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n, w;
    cin >> n >> w;
    int a[n],c[n];
    scanArray(c, n);
    scanArray(a, n);
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (a[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + c[i - 1]);
            }
        }
    }
    int res[n] = {0};
    int i = n, j = w;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            res[i - 1] = 1;
            j -= a[i - 1];
        }
        i--;
    }
    cout << dp[n][w] << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}
void scanArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}