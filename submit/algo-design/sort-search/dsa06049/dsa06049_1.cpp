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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long res = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        res += lower_bound(a + i + 1, a + n, a[i] + k) - (a + i + 1);
    }
    cout << res;
}