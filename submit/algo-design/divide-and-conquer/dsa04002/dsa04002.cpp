#include <iostream>
using namespace std;
void testCase();
const int MOD = 1e9 + 7;
long long powll(long long a, long long b);
long long reversed(long long a);
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
    long long k = reversed(n);
    long long res = powll(n, k);
    cout << res;
}
long long reversed(long long a) {
    long long res = 0;
    while (a > 0) {
        res = res * 10 + a % 10;
        a /= 10;
    }
    return res;
}
long long powll(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long res = powll(a, b / 2);
    res = (res * res) % MOD;
    if (b % 2 != 0) {
        res = (res * a) % MOD;
    }
    return res;
}