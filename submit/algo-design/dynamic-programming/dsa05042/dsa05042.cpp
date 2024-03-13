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
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++ ){
        cin >> a[i];
    }
    long long sum = a[0];
    int start = 0;
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