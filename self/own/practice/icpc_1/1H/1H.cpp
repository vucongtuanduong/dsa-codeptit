#include <bits/stdc++.h>
using namespace std;
int MAX = 1e6;
vector<long long> prime(MAX + 1, 0);
void init() {
    for (int i = 2; i <= MAX; i++) {
        if (prime[i] == 0) {
            for (int j = i; j <= MAX; j += i) {
                prime[j] = i;
            }
        }
    }
}

void testCase() {
    int n;
    cin >> n;
    long long a[n];
    long long res = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<long long,long long> mp;
    for (int i = 0; i < n; i++) {
        mp[prime[a[i]]]++;
    }
    for (auto x : mp) {
        if (x.second >= 2) {
            res = max(res, x.first);
        }
    } 
    cout << res;
}

int main() {
    // Write your code here
    init();
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
