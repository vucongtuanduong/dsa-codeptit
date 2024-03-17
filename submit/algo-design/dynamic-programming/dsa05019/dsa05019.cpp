#include <bits/stdc++.h>
using namespace std;
void testCase();
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
void testCase() {
    int n, m;
    cin >> n >> m;
    int a[501][501];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
        for (int j=  1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    int f[501][501];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) {
                f[i][j] = 0;
            } else {
                f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
            }
            res = max(res, f[i][j]);
        }
    }
    cout << res;
}