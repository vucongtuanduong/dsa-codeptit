#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Your code here
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
    vector<int> x(n), y(m);
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
        if (y[i] < 5) {
            count[y[i]]++;
        }
    }
    sort(y.begin(), y.end());
    int res = 0;
    for (int i = 0; i < x.size(); i++)  {
        if (x[i] == 1) {
            res += count[0];

        } else if (x[i] > 1) {
            auto index = upper_bound(y.begin(), y.end(), x[i]);
            int ans = y.begin() + m - index;
            ans += count[0] + count[1];
            if (x[i] == 2) {
                ans -= count[3] + count[4];

            }
            if (x[i] == 3) {
                ans += count[2];
            }
            res += ans;
        }
    }
    cout << res;
}