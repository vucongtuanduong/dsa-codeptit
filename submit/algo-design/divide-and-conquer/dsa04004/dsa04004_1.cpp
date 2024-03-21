#include <bits/stdc++.h>
using namespace std;
void testCase();
long long findNumber(long long n, long long k);
long long powll(long long n, long long k);
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
long long powll(long long n, long long k) {
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    long long x = powll(n, k  / 2);
    x = x * x;
    if (k % 2 == 1) {
        x = x * n;
    }
    return x;
}
long long findNumber(long long n, long long k) {
    // long long mid = (1LL << n) / 2;//mid = 2^(n-1)
    long long mid = powll(2, n - 1);
    if (k == mid) {
        return n;
    } else if (k < mid) {
        return findNumber(n - 1, k);
    } else {
        return findNumber(n - 1, k - mid);
    }
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    cout << findNumber(n, k);
}   