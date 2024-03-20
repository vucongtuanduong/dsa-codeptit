#include <bits/stdc++.h>
using namespace std;
int a[11], n;
string s;
vector<bool> used(11, false);
void testCase();
void Try(int i);
void solve();
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
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            used[j] = true;
            a[i] = j;
            if (i == n) {
                solve();
            } else {
                Try(i + 1);
            }
            used[j] = false;
        }
    }
}
void testCase() {
    used.resize(11, false);
    cin >> s;
    n = s.size();
    Try(1);
}
void solve() {
    for (int i = 1; i <= n; i++) {
        cout << s[a[i] - 1];
    }
    cout << " ";
}