#include <iostream>
#include <cmath>
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
    int n, s, m;
    cin >> n >> s >> m;
    if (n < m || 6 * (n - m) < m) {
        cout << "-1";
    } else {
        cout << ceil((float)m * s / n);
    }
}