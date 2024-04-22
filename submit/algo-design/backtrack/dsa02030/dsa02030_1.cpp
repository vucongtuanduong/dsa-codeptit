#include <bits/stdc++.h>
using namespace std;
int n, k;
char c;
int x[101];
void testCase();
void init();
void Try(int i);
void result();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void init() {
    cin >> c >> k;
    n = c - 'A';
    // cout << n << endl;
    x[0] = 0;
    for (int i = 1; i <= k; i++) {
        x[i] = i;
    }
}
void Try(int i) {
    for (int j = x[i - 1]; j <= n; j++) {
        x[i] = j;
        if (i == k) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void result() {
    for (int i = 1; i <= k; i++) {
        cout << (char)(x[i] + 'A');
        // cout << x[i];
    }
    cout << endl;
}
void testCase() {
    init();
    Try(1);
}