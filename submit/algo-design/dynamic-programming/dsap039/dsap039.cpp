#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
int dp[MAX][1 << MAX], a[MAX][MAX], n;
void testCase();
int Try(int i, int mask);
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
int Try(int i, int mask) {
    if (i == n) {
        return 0;
    }
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }
    int res = 0;
    for (int j = 0; j < n; j++) {
        if (!(mask & (1 << j))) {
            res = max(res, a[i][j] + Try(i + 1, mask | (1 << j)));
        }

    }
    return dp[i][mask] = res;
}
void testCase() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << Try(0, 0);
}