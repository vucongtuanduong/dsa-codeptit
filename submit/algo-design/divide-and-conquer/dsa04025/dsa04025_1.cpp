#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
struct matrix{
    long long x[2][2];
    friend matrix operator * (matrix a, matrix b) {
        matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    c.x[i][j] += a.x[i][k] * b.x[k][j];
                    c.x[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};
matrix binpow(matrix a, long long n);
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
    int n;
    cin >> n;
    matrix a;
    a.x[0][0] = 1;
    a.x[0][1] = 1;
    a.x[1][0] = 1;
    a.x[1][1] = 0;
    matrix res = binpow(a, n);
    cout << res.x[0][1];

}
matrix binpow(matrix a, long long n) {
    if (n == 1) {
        return a;
    }
    matrix temp = binpow(a, n / 2);
    if (n % 2 == 1) {
        return temp * temp * a;
    } else {
        return temp * temp;
    }
}