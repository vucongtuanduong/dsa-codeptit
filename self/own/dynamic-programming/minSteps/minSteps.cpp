 #include <bits/stdc++.h>
using namespace std;
int memo[100];
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
int main() {
    // Write your code here
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << dp(n);
    return 0;
}
