#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
void testCase();
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
    int  n, v;
    cin >> n >> v;
    int a[n + 1], c[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int dp[v + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + c[i]);
        }
    }
    cout << dp[v];

}   