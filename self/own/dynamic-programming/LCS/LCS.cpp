#include <bits/stdc++.h>
using namespace std;
//Longest Common Subsequence (LCS)
int LCS(vector<int> a) {
    int n = a.size();
    vector<int> dp(n + 1, 1);
    int res = 1;
    for (int i = 1; i <= n; i++) {
        // dp[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (a[i - 1] > a[j - 1]) {
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(res, dp[i]);
            }
        }
    }
    return res;
}
int main() {
    // Write your code here
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << LCS(a) << endl;
    return 0;
}
