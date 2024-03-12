#include <iostream>
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

void testCase(matrix a);

matrix binpow(matrix a, long long n);
int main() {
    // Write your code here
    int t;
    cin >> t;
    matrix a;
    a.x[0][0] = 1;
    a.x[0][1] = 1;
    a.x[1][0] = 1;
    a.x[1][1] = 0;
    while (t--) {
        testCase(a);
        cout << endl;
    }
    return 0;
}
matrix binpow(matrix a, long long n) {
    if (n == 1) {
        return a;
    }
    matrix tmp = binpow(a, n / 2);
    if (n % 2 == 1) {
        return tmp * tmp * a;
    } else {
        return tmp * tmp;
    }
}
void testCase(matrix a) {
    int n;
    cin >> n;
    matrix res = binpow(a, n);
    cout << res.x[0][1];

}