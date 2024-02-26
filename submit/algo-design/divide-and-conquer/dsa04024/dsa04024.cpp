#include <iostream>
using namespace std;
void testCase();
void mul(long long a[11][11], long long b[11][11]);
void pow(long long a[11][11], int k);
const int MOD = 1e9 + 7;
int n, k;
long long d[11][11] = {0};//temporary a matrix
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
void mul(long long a[11][11], long long b[11][11]) {
    long long c[11][11] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = c[i][j];
        }
        
    }
}
void pow(long long a[11][11], int k) {
    if (k == 1) {
        return;
    }
    pow(a, k / 2);
    mul(a, a);
    if (k % 2 == 1) {
        mul(a, d);
    }
}
void testCase() {
    
    cin >> n >> k;
    long long a[11][11] = {0};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];
        }
    }
    pow(a, k);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i][n - 1];
        res %= MOD;
    }
    cout << res;
}