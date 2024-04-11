#include <bits/stdc++.h>
using namespace std;
void testCase();
void scanArray(int *a, int n);
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
void scanArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void testCase() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m], c[k];
    scanArray(a, n);
    scanArray(b, m);
    scanArray(c, k);
    bool ok = false;
    int i = 0, j = 0, x = 0;
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    while (i < n && j < m && x < k) {
        if (a[i] == b[j] && b[j] == c[x]) {
            ok = true;
            cout << a[i] << " ";
            i++;
            j++;
            x++;
        } else if (a[i] < b[j]) {
            i++;
        } else if (b[j] < c[x]) {
            j++;
        } else {
            x++;
        }
    }
    if (!ok) {
        cout << "NO";
    }
}