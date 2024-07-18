#include <bits/stdc++.h>
using namespace std;

void testCase() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    a[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        b[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                b[j] = a[j - 1] + 2;
            } else {
                b[j] = max(b[j - 1], a[j]);
            }
        }
        vector<int> c(n, 0);
        c = a;
        a = b;
        b = c;

    }
    cout << n - a[n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}