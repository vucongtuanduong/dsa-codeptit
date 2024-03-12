#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long p[1001][1001];
void testCase();
void init();
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    memset(p, 0, sizeof(p));
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void init() {
    for (int i = 1; i < 1001; i++) {
        p[i][1] = i;
    }
    for (int i = 2; i < 1001; i++) {
        for (int j = 2; j <= i; j++) {
            p[i][j] = i * p[i - 1][j - 1] % MOD;
        }
    }
}
void testCase() {
    int n, k;
    cin >> n >> k;
    // cout << n << " " << k ;
    cout << p[n][k];
}