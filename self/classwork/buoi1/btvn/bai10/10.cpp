#include <bits/stdc++.h>
using namespace std;
void testCase();
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int count = 0;
    int x = sqrt(n);
    if (x * x == n && x % 2 == 0) {
        count++;
    }
    for (int i = 1; i < sqrt(n); i++) {
        if (n % i == 0) {
            if (i % 2 == 0) {
                count++;
            }
            if ((n / i) % 2 == 0) {
                count++;
            }
        }
    }
    cout << count;
}