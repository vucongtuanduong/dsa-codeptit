#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void testCase();
long long powll(long long n, long long k);
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
long long powll(long long n, long long k) {
    if (k == 0) {
        return 1;
    } 
    if (k == 1) {
        return n;
    }
    long long x = powll(n, k / 2);
    x = (x * x) % MOD;
    x %= MOD;
    if (k % 2 == 1) {
        x = (x * n) % MOD;
        x %= MOD;
    } 
    return x;
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    cout << powll(n, k);
}