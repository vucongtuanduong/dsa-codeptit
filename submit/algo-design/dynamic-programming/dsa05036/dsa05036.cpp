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
    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> increasing(n, 1), decreasing(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && b[i] < b[j]) {
                increasing[i] = max(increasing[i], increasing[j] + 1);
                decreasing[i] = max(decreasing[i], decreasing[j] + 1);
            }
        }
    }
    int res = max(*max_element(increasing.begin(), increasing.end()), *max_element(decreasing.begin(), decreasing.end()));
    cout << res;

}