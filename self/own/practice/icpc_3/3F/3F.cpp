#include <bits/stdc++.h>
using namespace std;

// const int mod = 1e9 + 7;
long long f[2][2], d[2][2];
long long a, b,mod;
void reset() {
    f[0][0] = f[0][1] = f[1][0] = 1, f[1][1] = 0;
    d[0][0] = d[0][1] = d[1][0] = 1, d[1][1] = 0;
}

void mul(long long f[2][2], long long b[2][2]) {
    long long x = (f[0][0] * b[0][0] % mod + f[0][1] * b[1][0] % mod) % mod;
    long long y = (f[0][0] * b[0][1] % mod + f[0][1] * b[1][1] % mod) % mod;
    long long z = (f[1][0] * b[0][0] % mod + f[1][1] * b[1][0] % mod) % mod;
    long long t = (f[1][0] * b[0][1] % mod + f[1][1] * b[1][1] % mod) % mod;
    f[0][0] = x, f[0][1] = y, f[1][0] = z, f[1][1] = t;
}

void powll(long long f[2][2], long long n) {
    if (n <= 1) return;
    powll(f, n / 2);
    mul(f, f);
    if (n % 2 == 1) mul(f, d);
}

void testCase() {
    reset();
    
    cin >> a >> b >> mod;
    long long x = __gcd(a, b);
    // int n; cin >> n;
    powll(f, x - 1);
    cout << f[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}