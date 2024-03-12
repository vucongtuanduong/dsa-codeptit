#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long f[2][2], d[2][2];
void testCase();
void reset();
void powMatrix(long long f[2][2], int n);
void Mul(long long a[2][2], long long b[2][2]);
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
void Mul(long long a[2][2], long long b[2][2]) {
    long long x = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
    long long y = (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD;
    long long z = (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
    long long t = (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
    f[0][0] = x, f[0][1] = y, f[1][0] = z, f[1][1] = t;
}
void powMatrix(long long f[2][2], int n) {
    if (n <= 1) {
        return;
    }
    powMatrix(f, n / 2);
    Mul(f,f);
    if (n % 2 == 1) {
        Mul(f, d);
    }
}
void reset() {
    f[0][0] = f[0][1] = f[1][0] = 1;
    f[1][1] = 0;
    d[0][0] = d[0][1] = d[1][0] = 1;
    d[1][1] = 0;
}
void testCase() {
    reset();
    int n;
    cin >> n;
    powMatrix(f, n - 1);
    cout << f[0][0];
}