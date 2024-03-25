#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
vector<vector<long long>> c(1001, vector<long long>(1001));
void testCase();
void init();
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
void testCase() {
    int n, k;
    cin >> n >> k;
    cout << c[n][k];
}
void init() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (i == 0 || j == 0 || j == i) {
                c[i][j] = 1;
            } else {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
                c[i][j] %= MOD; 
            }
        }
    }
}
