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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long x = 0, y = 0;
    int i = 0;
    while (i < n) {
        x = (x * 10) + a[i];
        i++;
        if (i != n) {
            y = (y * 10) + a[i];
            i++;
        }
    }
    cout << x + y;
} 