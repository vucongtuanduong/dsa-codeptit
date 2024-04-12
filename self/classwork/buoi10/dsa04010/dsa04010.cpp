#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
void testCase();
void init();
void maxSubArray(int l, int r);
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
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void maxSubArray(int l, int r) {
    int m = (l + r) / 2;
    int maxLeft = maxSubArray(l, m);
    int maxRight = maxSubArray(m + 1, r);
}
void testCase() {
    init();
    maxSubArray();
}