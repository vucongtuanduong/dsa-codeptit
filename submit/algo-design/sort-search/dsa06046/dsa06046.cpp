#include <iostream>
#include <algorithm>
using namespace std;
void testCase();
void testCase2();
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
void testCase2() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int res = 2e9;
    for (int i = 0; i < n - 1; i++) {

        res = min(res, a[i + 1] - a[i]);
     
    }
    cout << res;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int res = 1e9;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] < res) {
            res = a[i + 1] - a[i];
        }
    }
    cout << res;
}