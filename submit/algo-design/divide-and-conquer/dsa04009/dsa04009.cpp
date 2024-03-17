#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[11][11], d[11][11];
const int MOD = 1e9 + 7;
void Mul(long long a[11][11], long long b[11][11]);
void Pow(long long a[11][11], long long k);
void testCase();
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void Mul(long long a[11][11], long long b[11][11]) {
    long long c[11][11];
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = c[i][j];
        }
    }
}
void Pow(long long a[11][11], long long k) {
    if (k == 1) {
        return;
    }
    Pow(a, k / 2);
    Mul(a, a);
    if (k % 2 == 1) {
        Mul(a, d);
    }
}
void testCase() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];
        }
    }
    Pow(a, k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}