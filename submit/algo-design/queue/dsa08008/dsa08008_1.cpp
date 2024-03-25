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
    queue<string> q;
    q.push("1");
    while (true) {
        string s = q.front();
        q.pop();
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res = (res * 10 + s[i] - '0') % n;
        }
        if (res == 0) {
            cout << s;
            break;
        }
        q.push(s + "0");
        q.push(s + "1");
    }
}