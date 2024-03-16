#include <bits/stdc++.h>
using namespace std;
const int MAX = 15;
int n, dist[MAX][MAX], dp[MAX][1 << MAX];
void testCase();
int tsp(int i, int mask);
int main() {
    // Write your code here
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
int tsp(int i, int mask) {
    if (mask == (1 << n) - 1) {// all cities have been visited, return to city 0
        return 0;
    }
    if (dp[i][mask] != -1) {
        return dp[i][mask];// value already computed
    }
    int res = INT_MAX;
    for (int j = 0;j < n; j++) {
        if (i != j && !(mask & (1 << j))) {// if city j has not been visited
            res = min(res, dist[i][j] + tsp(j, mask | (1 << j)));
        }
    }
    dp[i][mask] = res;
    return dp[i][mask];

}
void testCase() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        res = min(res, tsp(i, 1 << i));
    }
    cout << res;
}