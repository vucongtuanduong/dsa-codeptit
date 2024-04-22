#include <bits/stdc++.h>
using namespace std;
int binarySearch(int *a, int l, int r, int x) {
    if (l >= r) {
        return -1;
    } 
    int m = (l + r) / 2;
    if (a[m] == x) {
        return m;
    } else if (a[m] < x) {
        return binarySearch(a, m + 1, r, x);
    }  else {
        return binarySearch(a, l, m, x);
    }
}
int main() {
    // Write your code here
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << binarySearch(a, 0, n - 1, x);
    return 0;
}
