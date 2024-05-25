#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    next_permutation(a.begin(), a.end());
    for (auto x : a) {
        cout << x << " ";
    }
}
void testCase2() {
    int n;
    cin >> n;
    int a[n + 1];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == (n - i + 1)) {
            cnt++;
        }
    }
    if (cnt == n) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        return;
    }
    int j = n - 1;
    while (a[j] > a[j + 1]) {
        j--;
    }
    int k = n;
    while (a[j] > a[k]) {
        k--;
    }
    swap(a[j], a[k]);
    int l = j + 1;
    int r = n;
    while (l <= r) {
        swap(a[l], a[r]);
        l++;
        r--;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase2();
        cout << endl;
    }
    return 0;
}
