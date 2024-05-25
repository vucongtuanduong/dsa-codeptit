#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long powll(long long n, long long k) {
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    long long res = powll(n, k / 2);
    res = (res * res) % MOD;
    if (k % 2 == 1) {
        res = res * n;
        res %= MOD;
    }
    return res;
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    cout << powll(n, k);
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
