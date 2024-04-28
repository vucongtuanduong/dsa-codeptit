#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    vector<int>a(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i =0 ; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }
    long long res = 0;
    while (pq.size() > 1) {
        int x= pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        res += x + y;
        pq.push(x + y);
    }
    cout << res;
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--){
        testCase();
        cout << endl;
    }
    return 0;
}
