#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& profits, int K) {
    int N = profits.size();
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));

    for (int i = 1; i <= N; ++i) {

        for (int j = 1; j <= K; ++j) {

            dp[i][j] = dp[i - 1][j];  // If we don't select the i-th project

            for (int k = 1; k <= i; ++k) {

                if (i - k + 1 >= j) {

                    dp[i][j] = std::max(dp[i][j], profits[i - 1] + dp[i - k][j - 1]);  // Selecting i-th project and the previous k-1 projects

                }

            }

        }

    }

    return dp[N][K];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i];
    }
    cout << "Maximum profit: " << maxProfit(projects, k) << endl;
    return 0;
}