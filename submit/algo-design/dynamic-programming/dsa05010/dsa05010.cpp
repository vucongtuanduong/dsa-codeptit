#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        vector<int> dp(k, -1);
        dp[0] = 0;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            vector<int> dpNext = dp;
            for (int j = 0; j < k; j++) {
                if (dp[j] != -1) {
                    dpNext[(j+A[i])%k] = max(dpNext[(j+A[i])%k], dp[j]+1);
                }
            }
            dp = dpNext;
            maxLength = max(maxLength, dp[0]);
        }
        cout << maxLength << "\n";
    }
    return 0;
}