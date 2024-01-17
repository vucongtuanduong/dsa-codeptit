#include <iostream>
using namespace std;
void testCase();
int binarySearch(int *a, int n, int x);
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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << binarySearch(a, n, x);

}
int binarySearch(int *a, int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (x < a[m]) {
            r = m - 1;
        } else if (x > a[m]) {
            l = m + 1;
        } else {
            return 1;
        }
    }
    return -1;
}