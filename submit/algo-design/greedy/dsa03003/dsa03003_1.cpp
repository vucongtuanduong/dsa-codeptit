#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
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
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += ((a[i] * i) % MOD);
        res %= MOD;
    }
    cout << res;
}