#include <iostream>
using namespace std;
void testCase();
long long findFloor(long long *a, long long n, long long x);
long long dvcFindFloor(long long *a, long long l, long long r, long long x); //divide and conquer approach
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
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // cout << dvcFindFloor(a, 0, n - 1, x);
    cout << findFloor(a, n, x);
}
long long dvcFindFloor(long long *a, long long l, long long r, long long x) {
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l ) / 2;
    if (a[mid] <= x && (mid == r|| x < a[mid + 1])) {
        return mid + 1;
    } else if (a[mid] < x) {
        return dvcFindFloor(a, mid + 1, r, x);
    } else {
        return dvcFindFloor(a, l, mid - 1, x);
    }
    return -1;
}
long long findFloor(long long *a, long long n, long long x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l ) / 2;
        if (a[mid] <= x && (mid == n - 1 || x < a[mid + 1])) {
            return mid + 1;
        } else if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}