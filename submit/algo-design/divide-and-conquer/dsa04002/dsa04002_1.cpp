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
void testCase() {
    long long n;
    cin >> n;
    long long x = n;
    long long k = 0;
    while (x > 0) {
        k = k * 10 + (x % 10);
        x /= 10;
    }
   long long res = powll(n, k);
   cout << res;
}
long long powll(long long n, long long k) {
    if (k == 0) {
        return 1;
    } 
    long long x = powll(n, k / 2);
    x = (x * x) % MOD;
    if (k % 2 == 1) {
        x = (x * n) % MOD;
    }
    return x;
}