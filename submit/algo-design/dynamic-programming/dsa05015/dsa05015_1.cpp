#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> p(1001, vector<long long>(1001, 0));
const int MOD = 1e9 + 7;

void init() {
    for (int i = 1; i < 1001; i++) {
        p[i][1] = i;
    }
    for (int i = 2; i < 1001; i++ ){
        for (int j = 2; j <= i; j++) {
            p[i][j] = i * p[i - 1][j - 1] % MOD;
        }
    }
}
void testCase() {
    int n, k;
    cin >> n >> k;
    cout << p[n][k];
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