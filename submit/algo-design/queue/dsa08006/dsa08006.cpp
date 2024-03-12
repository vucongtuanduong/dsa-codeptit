#include <bits/stdc++.h>
using namespace std;
void testCase();
bool check(string s, int n);
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
bool check(string s, int n) {
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        x = (x * 10 + s[i] - '0') % n;
    }
    return x == 0;
}
void testCase() {
    int n;
    cin >> n;
    queue<string> q;
    q.push("9");
    while (true) {
        string s = q.front();
        q.pop();
        if (check(s, n)) {
            cout << s ;
            return;
        }
        q.push(s + "0");
        q.push(s + "9");
    }
}