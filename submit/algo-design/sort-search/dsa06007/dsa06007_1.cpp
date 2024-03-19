#include <bits/stdc++.h>
using namespace std;
void testCase();
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
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (a[l] == b[l]) {
        l++;
    }
    while (a[r] == b[r] && r > l) {
        r--;
    }
    cout << l + 1 << " " << r + 1;
}