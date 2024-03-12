#include <iostream>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    int f[n];
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        res = max(res, f[i]);
    }
    cout << res;
}