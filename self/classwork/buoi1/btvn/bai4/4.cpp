#include <bits/stdc++.h>
using namespace std;
void testCase();
int main () {
    int t;
    cin >> t;
    for  (int i = 1; i <= t; i++) {
        cout << "Test " << i << ": ";
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++) {
        int count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count) {
            cout << i << "(" << count << ") ";
        }
    }
    if (n > 1) {
        cout << n << "(1)";
    }
}