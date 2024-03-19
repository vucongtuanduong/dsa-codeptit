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
    int n, x;
    cin >> n >> x;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += upper_bound(a.begin() + i + 1, a.end(), x - a[i]) - lower_bound(a.begin() + i + 1, a.end(), x - a[i]);
    }
    cout << count;
}