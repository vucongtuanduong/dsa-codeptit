#include <bits/stdc++.h>
using namespace std;
void testCase() {
    long long n;
    cin >> n;
    queue<long long> q;
    long long cnt= 0 ;
    q.push(1);
    while (q.front() <= n) {
        long long temp  = q.front();
        q.pop();
        cnt++;
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
