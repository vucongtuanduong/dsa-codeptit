#include <bits/stdc++.h>
using namespace std;
long long f[30];
void prepare();
long long powll(long long n, long long k);
int find(long long n, long long k);
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    prepare();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
int find(long long n, long long k) {
    long long total = powll(2, n - 1);
    if (k == total) {
        return n + 'A' - 1;
    } else if (k < total) {
        return find(n - 1, k);
    }
    return find(n - 1, k - total);
}
long long powll(long long n, long long k) {
    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return n;
    }
    long long x=  powll(n , k / 2);
    x *= x;
    if (k % 2 == 1) {
        x *= n;
    }
    return x;
}
void prepare() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < 30; i++ ) {
        f[i] = f[i - 1] * 2;
    }
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    cout << (char)find(n, k);
}