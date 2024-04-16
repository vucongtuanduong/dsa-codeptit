#include <bits/stdc++.h>
using namespace std;

void testCase();
bool cmp(pair<int,int> a, pair<int, int> b);

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}

bool cmp(pair<int,int> a, pair<int, int> b) {
    double x = (1.0 * a.second) / a.first; // ratio of value to weight for pair a
    double y = (1.0 * b.second) / b.first; // ratio of value to weight for pair b
    return x > y;
}

void testCase() {
    int n, v;
    cin >> n >> v;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first; // weight
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second; // value
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> dp(v + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = v; j >= a[i].first; j--) {
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
        }
    }
    cout << dp[v];
}
