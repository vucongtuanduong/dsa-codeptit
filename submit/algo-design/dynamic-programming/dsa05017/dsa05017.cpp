#include <bits/stdc++.h>
using namespace std;
void testCase();
int maxBitonicSum(vector<int> a);
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
int maxBitonicSum(vector<int> a) {
    int n = a.size();
    int inc[n], dec[n];
    for (int i = 0; i < n; i++) {
        inc[i] = a[i];
        dec[i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && inc[i] < inc[j] + a[i]) {
                inc[i] = inc[j] + a[i];
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j] && dec[i] < dec[j] + a[i]) {
                dec[i] = dec[j] + a[i];
            }
        }
    }
    int max = inc[0] + dec[0] - a[0];
    for (int i = 1; i < n; i++) {
        if (inc[i] + dec[i] - a[i] > max) {
            max = inc[i] + dec[i] - a[i];
        }
    }
    return max;
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxBitonicSum(a);
}