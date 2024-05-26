#include<bits/stdc++.h>
using namespace std;

int n, m, a[10], dp[100005], trace[100005];

void testCase() {
    
    cin >> n >> m;
    for (int i = 0; i < 10; i++) a[i] = 1e9;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        if (x == 0) a[0] = min(a[0], 6);
        if (x == 1) a[1] = min(a[1], 2);
        if (x == 2) a[2] = min(a[2], 5);
        if (x == 3) a[3] = min(a[3], 5);
        if (x == 4) a[4] = min(a[4], 4);
        if (x == 5) a[5] = min(a[5], 5);
        if (x == 6) a[6] = min(a[6], 6);
        if (x == 7) a[7] = min(a[7], 3);
        if (x == 8) a[8] = min(a[8], 7);
        if (x == 9) a[9] = min(a[9], 6);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = -1e9;
        for (int j = 0; j < 10; j++) {
            if (i >= a[j] && dp[i] < dp[i - a[j]] + 1) {
                dp[i] = dp[i - a[j]] + 1;
                trace[i] = j;
            }
        }
    }
    if (dp[n] < 0) {
        cout << -1;
        return;
    }
    while (n > 0) {
        cout << trace[n];
        n -= a[trace[n]];
    }
    
}
int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }

    return 0;
}