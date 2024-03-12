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
    int m,n,k;
    cin >> m >> n >> k;
    int a[m + n];
    for (int i = 0; i < m + n; i++) {
        cin >> a[i];
    }
    sort(a,a + m + n);
    cout << a[k - 1];
}