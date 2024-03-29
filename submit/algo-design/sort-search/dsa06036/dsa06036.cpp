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
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase2() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int index = upper_bound(a + j + 1, a + n, k - a[i] - a[j]) - (a + j + 1);
            if (index != -1) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
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