#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1001;
long long c[MAX][MAX];
void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == 0 || j == 0 || j == i) {
                c[i][j] = 1;
            } else {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }
}
void testCase() {
    int n, k;
    cin >> n >> k;
    cout << c[n][k];
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
