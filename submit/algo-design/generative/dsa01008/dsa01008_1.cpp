#include <bits/stdc++.h>
using namespace std;
int a[17], n, k;
void testCase();
void Try(int i);
void solve();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void testCase() {
    cin >> n >> k;
    Try(1);
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            solve();
        } else {
            Try(i + 1);
        }
    }
}
void solve() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            count++;
        }
    }
    if (count == k) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] ;
        }
        cout << endl;
    }
}