#include <iostream>
#include <algorithm>
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
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    int res = -1, min = a[0].second, k = a[0].first;
    for (int i = 1; i < n; i++) {
        if (a[i].first > k) {
            res = max(res, a[i].second - min);
        }
        if (min > a[i].second) {
            min = a[i].second;
            k = a[i].first;
        }
    }
    cout << res;
}