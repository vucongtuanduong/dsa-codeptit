#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
vector<int> prime(MAX, true);
void init() {
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = false;
            }   
        }
    }
}
int largestPrimeFactor(int n) {
    int res = 0;
    int m = n;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) {
            res = max(res, i);
        }
    }   
    if (n > 1) {
        res = max(res, n);
    }
    // cout << "largest prime factor of " << m << ": " << res << endl;
    return res;
}
void testCase() {
    int l, r;
    cin >> l >> r;
    long long sum = 0;
    for (int i = l; i <= r; i++) {
        if (prime[i]) {
            sum += i;
        } else {
            sum += largestPrimeFactor(i);
        }
        // cout << "sum : " << sum << endl;
        
    }
    cout << sum;
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
