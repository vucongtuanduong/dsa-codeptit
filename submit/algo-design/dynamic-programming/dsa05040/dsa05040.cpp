#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> increasing(n, 1), decreasing(n, 1);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            increasing[i] = increasing[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            decreasing[i] = decreasing[i + 1] + 1;
        }
    }
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        max_length = max(max_length, increasing[i] + decreasing[i] - 1);
    }
    cout << max_length;
}