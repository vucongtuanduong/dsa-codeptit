#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
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
    int a[n + 1];
    int count = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == (n - i + 1)) {
            count++;
        }

    }
    if (count == n) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        return;
    } else {
        int t = n - 1;
        while (a[t] > a[t + 1]) {
            t--;
        }
        int k = n;
        while (a[k] < a[t]) {
            k--;
        }
        swap(a[t], a[k]);
        int l = t + 1, r = n;
        while (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
    }

}