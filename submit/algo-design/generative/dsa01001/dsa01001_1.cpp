#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    string s;
    cin >> s;
    int i = s.size() - 1;
    while (s[i] == '1') {
        s[i] = '0';
        i--;
    }
    if (i < 0) {
        for (int i = 0; i <= s.size(); i++) {
            cout << '0';
        }
    } else {
        s[i] = '1';
        cout << s;
    }
    
    
}