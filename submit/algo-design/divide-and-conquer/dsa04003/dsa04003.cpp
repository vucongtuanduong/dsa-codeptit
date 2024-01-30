#include <iostream>
using namespace std;
const int MOD = 123456789;
void testCase();
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
    long long n;
    cin >> n;
    long long res = powll(2, n - 1);
    cout << res;
}
long long powll(long long a, long long b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    }
    long long res = powll(a, b / 2);
    res = (res * res) % MOD;
    if (b % 2 == 0) {
        return res;
    } else {
        res = (a * res) % MOD;
        return res;
    }
}