#include <bits/stdc++.h>
using namespace std;
void testCase();
long long floor(vector<long long> a, int l, int r, long long x);
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
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << floor(a, 0, n -1, x);

}
long long floor(vector<long long> a, int l, int r, long long x) {
    if (l > r) {
        return -1;
    }
    int m = (l + r) / 2;
    if (a[m] <= x && (m == r || x < a[m + 1])) {
        return m + 1; 
    } else if (a[m] < x) {
        return floor(a, m + 1, r, x);
    } else {
        return floor(a, l, m - 1, x);
    }
}