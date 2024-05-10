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
    for (int i = 1; i < MAX; i++) {
        p[i][1] = i;
    }
    for (int i = 2; i < MAX; i++) {
        for (int j = 2; j < MAX; j++) {
            if (j == 0 || j == MAX || j == i) {
                p[i][j] = i;
            } else {
                p[i][j] = p[i - 1][j - 1] * i;
                p[i][j] %= MOD;
            }
        }
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    init();
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
