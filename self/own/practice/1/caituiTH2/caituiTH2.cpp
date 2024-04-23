#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, m;
    cin >> n >> m;

    pair<int,int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int dp[m + 1] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= a[i].first; j--) {
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
        }
    }
    cout << dp[m];
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
