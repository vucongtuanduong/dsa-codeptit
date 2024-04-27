#include <bits/stdc++.h>
using namespace std;
int maxBitonicSum(vector<int> a, int n) {
    vector<int> increasing = a, decreasing = a;
    for(int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && increasing[i] < increasing[j] + a[i]) {
                increasing[i] = increasing[j] + a[i];
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j] && decreasing[i] < decreasing[j] + a[i]) {
                decreasing[i] = decreasing[j] + a[i];
            }
        }
    }
    int res = increasing[0] + decreasing[0] - a[0];
    for (int i = 1; i < n; i++) {
        if (increasing[i] + decreasing[i] - a[i] > res) {
            res = increasing[i] + decreasing[i] - a[i];
        }
    }
    return res;

}
void testCase() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxBitonicSum(a, n);
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
