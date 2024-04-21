#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    string res = s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            s[i] = '1';
        } else {
            s[i] = '0';
        }
    }
    cout << s;
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
