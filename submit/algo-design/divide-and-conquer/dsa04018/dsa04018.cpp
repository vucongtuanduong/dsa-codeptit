#include <iostream>
#include <algorithm>
using namespace std;
void testCase();
int count0s(int *a, int l, int r);
int main() {
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
    cout << lower_bound(a, a + n, 1) - a;
}