#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    
    queue<string> q;
    q.push("9");
    while( true) {
        string s = q.front();
        q.pop();
        int temp = 0;
        for (int i = 0; i < s.size(); i++) {
            temp = (temp * 10 + s[i] - '0') % n;
        }
        if (temp == 0) {
            cout << s;
            return;
        }
        q.push(s + "0");
        q.push(s + "9");
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
