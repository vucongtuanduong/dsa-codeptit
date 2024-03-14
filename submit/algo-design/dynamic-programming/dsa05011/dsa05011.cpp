#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(K+1, vector<int>(10)));
        for (int digit = 1; digit <= 9; digit++) {
            if (digit <= K) {
                dp[1][digit][digit] = 1;
            }
        }
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                for (int k = 0; k <= 9; k++) {
                    if (j >= k) {
                        for (int l = 0; l <= 9; l++) {
                            dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-k][l]) % MOD;
                        }
                    }
                }
            }
        }
        int result = 0;
        for (int k = 0; k <= 9; k++) {
            result = (result + dp[N][K][k]) % MOD;
        }
        cout << result << "\n";
    }
    return 0;
}