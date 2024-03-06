#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.end());
    long long res = 0;
    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long now = (first + second) % MOD;
        res = (res + now) % MOD;
        pq.push(now);
    }
    cout << res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}