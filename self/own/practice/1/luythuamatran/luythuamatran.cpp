#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long n, k;
vector<vector<long long>>a(11, vector<long long>(11)), d(11, vector<long long>(11));
void mul(vector<vector<long long>> &a, vector<vector<long long>> b) {
    vector<vector<long long>> c(11, vector<long long>(11));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += (a[i][k] * b[k][j]);
                c[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            a[i][j] = c[i][j];
        }
    }
}
void powll(vector<vector<long long>> &a, long long k) {
    if (k == 1) {
        return;
    }
    powll(a, k / 2);
    mul(a, a);   
    if (k % 2 == 1) {
        mul(a, d);
    }
}
void testCase() {
    
    cin >> n >> k;
    // a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];
        }
    }
    powll(a, k);
    long long res = 0;

    for (int i = 0; i < n; i++) {
        res += a[i][i];
        res %= MOD;    
    }
    cout << res;
}
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
