#include <bits/stdc++.h>
using namespace std;
void testCase();
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
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n, 1);
    int res = 0;
    for (int i = 1;i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] >= a[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        
    }
    // for (int i = 0;i < n; i++) {
    //     cout << dp[i] << " ";
    // }
    cout << n - *max_element(dp.begin(), dp.end());
}