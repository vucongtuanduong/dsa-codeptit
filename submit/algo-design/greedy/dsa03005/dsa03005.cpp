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
    int n, k;
    cin >> n >> k;
    k = min(k, n - k);
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long min = 0;
    long long max = 0;
    for (int i = 0; i < k; i++) {
        min += a[i];
    }
    for (int i = k; i < n; i++) {
        max += a[i];
    }
    cout  << max - min;
}