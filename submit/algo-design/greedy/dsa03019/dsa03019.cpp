#include <bits/stdc++.h>
using namespace std;
void testCase();
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
    long long p,q;
    cin >> p >> q;
    while (true) {
        if (q % p == 0) {
            cout << "1/" << q / p;
            return;
        }
        long long x = q/p + 1;
        cout << "1/" << x << " + ";
        p = p * x - q;
        q *= x;
    }
}