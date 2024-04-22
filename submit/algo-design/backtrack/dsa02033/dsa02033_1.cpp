#include <bits/stdc++.h>
using namespace std;
int n;
int x[101];
bool used[101];
void testCase();
void init();
bool check();
void result();
void Try(int i);
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
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            x[i] = j;
            used[j] = true;
            if (i == n) {
                if (check()) {
                    result();
                }
            } else {
                Try(i + 1);
            }
            used[j] = false;
        }
    }
}
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        x[i] = i;
        used[i] = false;
    }
}
bool check() {
    for (int i = 2; i <= n; i++) {
        int diff= abs(x[i] - x[i - 1]);
        if (diff == 1) {
            return false;
        }
    }
    return true;
}
void result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void testCase() {
    init();
    Try(1);
}