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
    long long n;
    cin >> n;
    queue<string> q;
    q.push("1");
    long long count = 0;
    while (true) {
        string s = q.front();
        q.pop();
        long long x = stoll(s);
        if (x < n) {
            count++;
        } else {
            cout << count;
            return;
        }
        q.push(s + "0");
        q.push(s + "1");
    }
}