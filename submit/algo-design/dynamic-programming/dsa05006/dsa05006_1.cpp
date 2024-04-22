#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dp[n] = {0};
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = a[i];
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] ) {
                dp[i] =  max(dp[i], dp[j] + a[i]);
            }
        }
    }
    cout << *max_element(dp, dp + n);
}
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
