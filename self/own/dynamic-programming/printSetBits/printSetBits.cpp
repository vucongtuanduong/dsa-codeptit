#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    int n = 10;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i / 2] + (i % 2);
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}
