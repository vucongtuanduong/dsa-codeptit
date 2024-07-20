#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
vector<int> prime(MAX + 1, 0);
void sieve() {
    for (int i = 2; i <= MAX; i++) {
        if (prime[i] == 0) {
            for (int j = i; j <= MAX;j += i) {
                prime[j] = i;
            }
        }
    }
}
void testCase() {
    int l, r;
    cin >> l >> r;
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += prime[i];
    }
    cout << sum;
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    sieve();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
