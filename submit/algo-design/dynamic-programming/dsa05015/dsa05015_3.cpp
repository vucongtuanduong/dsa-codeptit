#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1005;
long long p[MAX][MAX] = {0};

void testCase() {
    int n, k;
    cin >> n >> k;
    cout << p[n][k];
}

void init() {
    for (int i = 0; i < MAX; i++) {
        p[i][0] = 1; // P(n, 0) = 1
    }
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j <= i; j++) {
            p[i][j] = (p[i - 1][j] + j * p[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    int t;
    cin >> t;
    init();
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}