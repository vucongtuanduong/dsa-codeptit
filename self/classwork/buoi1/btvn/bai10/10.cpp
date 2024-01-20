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
    // testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            if (i % 2 == 0) {
                count++;
            }
            n /= i;
        }
    }
    cout << count;
}