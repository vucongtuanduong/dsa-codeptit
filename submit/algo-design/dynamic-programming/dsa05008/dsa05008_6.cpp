#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = s; j >= a[i]; j--) {
            if (dp[j] == 0 && dp[j - a[i]]) {
                dp[j] = 1;
            }
        }
    }
    if (dp[s]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
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
