#include <bits/stdc++.h>
using namespace std;
void testCase() {
    long long n;
    cin >> n;
    queue<long long> q;
    q.push(1);
    int cnt = 0;
    while(q.front() <= n) {
        cnt++;
        long long temp = q.front();
        q.pop();
        q.push(temp * 10);
        q.push(temp * 10 + 1);
    }
    cout << cnt;
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
