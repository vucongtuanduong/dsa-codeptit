#include <bits/stdc++.h>
using namespace std;
void testCase();
void testCase2();
int binarySearch(int *a, int n, int x);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase2();
        cout << endl;
    }
    return 0;
}
void testCase2(){ 
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    cout << binary_search(a,a + n, x);
}
void testCase(){ 
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    cout << binarySearch(a, n, x);
}
int binarySearch(int *a, int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            return mid + 1;
        }
        if (a[mid] <= a[r]) {
            if (x > a[mid] && x <= a[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            if (x >= a[l] && x < a[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return -1;
}