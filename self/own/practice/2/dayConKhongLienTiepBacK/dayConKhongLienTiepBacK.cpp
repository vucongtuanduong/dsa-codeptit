#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dp[n] = {0};
    for (int i = 0; i < n; i++) {
        dp[i] = a[i];
        if (i + 1 > k) {
            dp[i] = max(dp[i], dp[i - k] + a[i]);
        }
    }
    cout << *max_element(dp, dp + n);
    return 0;
}