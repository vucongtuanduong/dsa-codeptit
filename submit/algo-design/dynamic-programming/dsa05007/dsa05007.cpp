#include <bits/stdc++.h>
using namespace std;
void testCase();
long long maxSum(vector<int> a);
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
long long maxSum(vector<int> a) {
    int n = a.size();
    if (n == 1) {
        return a[0];
    }
    vector<long long> dp(n, 0);
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
    }
    return dp[n - 1];
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxSum(a);

}