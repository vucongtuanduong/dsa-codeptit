#include <iostream>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int c, n;
    cin >> c >> n;
    int w[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    int dp[c + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = c; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    cout << dp[c];
}