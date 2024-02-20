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
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && a[i] != b[n - i - 1]) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}