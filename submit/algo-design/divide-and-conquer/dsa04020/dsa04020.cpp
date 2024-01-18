#include <iostream>
using namespace std;
void testCase();
int binarySearch(int *a, int l, int r, int x);
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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = binarySearch(a, 0, n - 1, k);
    if (res != -1) {
        cout << res + 1;
    }  else {
        cout << "NO";
    }
}
int binarySearch(int *a, int l, int r, int x) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (x > a[m]) {
            l = m + 1;
        } else if (x < a[m]) {
            r = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}