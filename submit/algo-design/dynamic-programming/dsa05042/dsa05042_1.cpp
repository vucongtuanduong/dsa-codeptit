#include <bits/stdc++.h>
using namespace std;
void testCase() {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = a[0];
    long long start = 0;
    for (int i = 1; i <= n; i++) {
        while (sum > k && start < i - 1) {
            sum -= a[start];
            start++;
        }
        if (sum == k) {
            cout << "YES";
            return;
        }
        if (i < n) {
            sum += a[i];
        }
    }
    cout << "NO";
}
int main() {
    // Write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
