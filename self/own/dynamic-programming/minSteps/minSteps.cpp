#include <bits/stdc++.h>
using namespace std;
vector<int>memo;
void testCase();
int dp(int n);
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

int dp(int n) {
    if (n == 1) {
        return 0;
    }
    int &ans = memo[n];
    if (ans != -1) {
        return ans;
    }
    ans = INT_MAX;
    if (n % 2 == 0) {
        ans = min(ans, dp(n / 2));
    }
    if (n % 3 == 0) {
        ans = min(ans, dp(n / 3));
    }
    ans = min(ans, dp(n - 1));
    ans ++;
    return ans;
}
void testCase() {
    int n;
    cin >> n;
    memo.resize(n + 1, -1);
    cout << dp(n);
}