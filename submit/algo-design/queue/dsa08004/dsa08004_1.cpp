#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int dd[127] = {};
    for (char x : s) {
        dd[x]++;
    }
    priority_queue<int> pq;
    for (int m :  dd) {
        if (m > 0) {
            pq.push(m);
        }
    }
    while (k--) {
        if (pq.empty()) {
            break;
        }
        int x  = pq.top();
        pq.pop();
        x--;
        pq.push(x);
    }
    long long res = 0;
    while (!pq.empty()) {
        long long x = pq.top();
        pq.pop();
        x *= x;
        res += x;
    }
    cout << res;
}
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
