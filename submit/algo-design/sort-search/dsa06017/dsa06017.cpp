#include <iostream>
#include <algorithm>
using namespace std;
void testCase() {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
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
