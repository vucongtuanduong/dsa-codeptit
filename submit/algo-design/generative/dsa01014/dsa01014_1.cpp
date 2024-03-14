#include <bits/stdc++.h>
using namespace std;
int n, k, s, res;
int a[25];
void solve();
void Try(int i);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    while (true) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) {
            break;
        }
        res = 0;
        Try(1);
        cout << res << endl;
    }
    return 0;
}
void solve() {
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i];
    }
    if (sum == s) {
        res++;
    }
}
void Try(int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) {
            solve();
        } else {
            Try(i + 1);
        }
    }
}