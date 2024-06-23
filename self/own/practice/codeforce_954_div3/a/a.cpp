#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a, a + 3);
    cout << abs(a[2] - a[0]);
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
