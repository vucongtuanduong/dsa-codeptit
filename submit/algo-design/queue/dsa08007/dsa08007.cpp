#include <bits/stdc++.h>
using namespace std;
void testCase();
int countBDN(long long n);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    long long  n;
    cin >> n;
    cout << countBDN(n);
}
int countBDN(long long n) {
    queue<string> q;
    q.push("1");
    int count = 0;
    while (true) {
        string s= q.front();
        q.pop();
        if (stoll(s) < n) {
            count++;
            q.push(s + "0");
            q.push(s + "1");
        } else {
            break;
        }
        
    }
    return count;
}