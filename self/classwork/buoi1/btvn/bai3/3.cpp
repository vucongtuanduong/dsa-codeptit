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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}