#include <iostream>
#include <vector>
using namespace std;

long long catalan(int n) {
    vector<long long> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << catalan(n) << endl;
    }
    return 0;
}