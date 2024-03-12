#include <iostream>
using namespace std;
void testCase();
void scanArray(int *a, int n);
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
void testCase() {
    int n, v;
    cin >> n >> v;
    int a[n + 1];
    int c[n + 1];
    scanArray(a, n);
    scanArray(c, n);
    int dp[v + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= a[i]; j--) {
            dp[j] = max(dp[j - a[i]] + c[i], dp[j]);
        }
    }
    cout << dp[v];
}
void scanArray(int *a, int n) {
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}