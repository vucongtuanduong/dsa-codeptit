#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int countNumbers(int N) {
    vector<vector<int>> dp(N+1, vector<int>(10));
    for (int j = 0; j <= 9; j++) {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }
    int count = 0;
    for (int j = 0; j <= 9; j++) {
        count = (count + dp[N][j]) % MOD;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << countNumbers(N) << endl;
    }
    return 0;
}