#include <bits/stdc++.h>
using namespace std;
void testCase() {
    long long n;
    cin >> n;
    queue<long long> q;
    long long cnt= 0 ;
    q.push(1);
    while (true) {
        long long temp  = q.front();
        q.pop();
        if (temp % n == 0) {
            cout << temp;
            return;
        }
        q.push(temp * 10);
        q.push(temp * 10 + 1);
    }
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
