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
    string s;
    cin >> s;
    cout << s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == '1') {
            cout << '1' - s[i];
        } else {
            cout << s[i];
        }
    }
}