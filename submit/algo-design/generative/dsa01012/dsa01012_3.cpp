#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
void result() {
    cout << a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] == 1) {
            cout << 1 - a[i];
        } else {
            cout << a[i];
        }
    }
    cout << " ";
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            result();
        } else {
            Try(i + 1);
        }
    }
    
}
void testCase() {
    cin >> n;
    Try(1);
}
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
