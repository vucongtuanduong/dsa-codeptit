#include <bits/stdc++.h>
using namespace std;
int a[20][20], res;
bool xuoi[20], nguoc[20], b[20];
int n = 8;
void testCase();
void Try(int i, int sum);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void Try(int i, int sum) {
    for (int j = 1; j <= n; j++) {
        if (!b[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]) {
            b[j] = xuoi[i - j + n] = nguoc[i + j - 1] = true;
            sum += a[i][j];
            if (i == 8) {
                res = max(res, sum);
            } else {
                Try(i + 1, sum);
            }
            sum -= a[i][j];
            b[j] = xuoi[i - j + n] = nguoc[i + j - 1] = false;
        }
    }
}
void testCase() {
    res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    Try(1, 0);
    cout << res;
}