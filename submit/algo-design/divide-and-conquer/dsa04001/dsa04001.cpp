#include <iostream>
using namespace std;
void testCase();
const int MOD = 1e9 + 7;
long long powll(long long a, long long b);
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
    long long n, k;
    cin >> n >> k;
    long long res = powll(n, k);
    cout << res;
}
long long powll(long long a, long long b) {
    if (b == 1) {
        return a;
    }
    if (b == 0) {
        return 1;

    }
    long long res = powll(a, b / 2);
    if (b % 2 == 0) {
        res = (res * res) % MOD;
    } else {
        res = a * ((res * res) % MOD);
        res %= MOD;
    }
    return res;
}