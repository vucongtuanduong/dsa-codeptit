#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> f(n + 1, 0);
    int l_max = 0;
    for (int i = 0; i < n; i++) {
        f[a[i]] = f[a[i] - 1] + 1;
        l_max  = max(l_max, f[a[i]]);
    }
    cout << n - l_max;
}