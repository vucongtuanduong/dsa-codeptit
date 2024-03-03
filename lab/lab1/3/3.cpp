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
    int n, m;
    cin >> n >> m;
    int x = n + m;
    int a[x];
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    sort(a, a + x);
    for (int i = 0; i < x; i++) {
        cout << a[i] << " ";
    }
}