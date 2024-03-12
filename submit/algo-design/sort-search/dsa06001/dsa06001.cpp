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
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    sort(b, b + n, greater<int>());
    int i = 0, j = 0;
    while (i <= n/ 2 && j < n / 2) {
        cout << b[j++] << " " << a[i++] << " ";
    }
}