#include <bits/stdc++.h>
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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int index = upper_bound(a + j + 1, a + n, k - a[i] - a[j]) - lower_bound(a + j + 1, a + n, k - a[i] - a[j]);
            if (index != 0) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}