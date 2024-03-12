#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> matrix(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matrix[i][j];
            }
        }
        vector<int> dp(N);
        int maxSum = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[j] = max(dp[j] + matrix[i][j], matrix[i][j]);
                maxSum = max(maxSum, dp[j]);
            }
        }
        cout << maxSum << endl;
    }
    return 0;
}
