#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void testCase() {
    long long res = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>>  pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }
    while(pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        long long temp = (x + y) % MOD;
        res += temp;
        res %= MOD;
        pq.push(temp);
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
