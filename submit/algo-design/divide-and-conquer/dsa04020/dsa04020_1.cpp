#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> a, int k) {
    int n = a.size();
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r)  / 2;
        if (a[mid] == k) {
            return mid + 1;
        } else if (a[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];

    }
    int res = binarySearch(a, k);
    if (res == -1) {
        cout << "NO";
    } else {
        cout << res;
    }
}
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
