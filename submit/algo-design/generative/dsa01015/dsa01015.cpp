#include <bits/stdc++.h>
using namespace std;


string findNum(int n);
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << findNum(n) << endl;
    }
    return 0;
}
string findNum(int n) {
    queue<string> q;
    q.push("9");
    while (true) {
        string s = q.front();
        q.pop();
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            x = x * 10 + (s[i] - '0');
            x %= n;
        }
        if (x == 0) {
            return s;
        }
        q.push(s + "0");
        q.push(s + "9");
    }
}   