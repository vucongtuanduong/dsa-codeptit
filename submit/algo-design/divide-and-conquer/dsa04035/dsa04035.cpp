#include <iostream>
using namespace std;
void testCase();
const int MOD = 1e9 + 7;
long long powll(long long a, long long b);
int main() {
    // Write your code here
    // int t;
    // cin >> t;
    // while (t--) {
    //     testCase();
    //     cout << endl;
    // }
    testCase();
    return 0;
}
void testCase() {
    long long a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            return;
            
        } else {
            cout << powll(a, b) << endl;
        }
        
    }
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