#include <bits/stdc++.h>
using namespace std;
long long fibo[93];
void init() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 93; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
int solve(long long n, long long k) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (k > fibo[n - 2]) {
        return solve(n - 1, k - fibo[n - 2]);
    }
    return solve(n - 2, k);
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    cout << solve(n, k);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
