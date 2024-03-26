#include <bits/stdc++.h>
using namespace std;
void testCase();
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
void testCase() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    long long res = 0;
    while (pq.size() > 1) {
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        res += (a + b);
        pq.push(a + b);
    }
    cout << res;
}