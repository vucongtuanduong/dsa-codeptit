#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
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
    int n, k;
    cin >> n >> k;
    long long f[10001] = {0};
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i - k; j <= i - 1; j++) {
            if (j >= 0) {
                f[i] = (f[i] + f[j]) % MOD;
            }
        }
    }
    cout << f[n];
}