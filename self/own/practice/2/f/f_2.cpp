#include <bits/stdc++.h>
using namespace std;
void testCase() {
    long long n, s, k;
    cin >> n >> s >> k;
    long long a[n + 1];
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i <= s) {
            sum += a[i];
        }
        
    }
    if (sum <= k) {
        cout << "1";
        return;
    }
    for (int i = 1; i < s; i++) {
        sum -= a[i];
        if (sum  <= k) {
            cout << i + 1;
            return;
        }
        // sum -= a[i];
    }
    cout << "-1";
}
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
