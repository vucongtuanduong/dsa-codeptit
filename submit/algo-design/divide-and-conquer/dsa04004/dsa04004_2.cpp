#include <bits/stdc++.h>
using namespace std;
long long powll(long long n, long long k) {
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    long long res = powll(n, k / 2);
    res = (res * res) ;
    if (k % 2 == 1) {
        res = res * n;
    }
    return res;
}
long long findNum(long long n, long long k) {
    long long mid = powll(2, n - 1);
    if (k == mid) {
        return n;
    } else if (k > mid) {
        return findNum(n - 1, k - mid);
    } else {
        return findNum(n - 1, k);
    }
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    cout << findNum(n, k);
}
int main() {
    // Write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
