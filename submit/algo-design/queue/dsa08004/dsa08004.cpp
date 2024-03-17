#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int k; cin >> k;
    string s; cin >> s;
    int dd[127] = {};
    for (char i : s) dd[i]++;
    priority_queue<int> q;
    for (int i : dd) {
        if (i > 0) q.push(i);
    }
    while (k--) {
        if (q.empty()) break;
        int x = q.top(); q.pop();
        x--;
        q.push(x);
    }
    long long ans = 0;
    while (!q.empty()) {
        long long x = q.top(); q.pop();
        ans += x * x;
    }
    cout << ans;
}