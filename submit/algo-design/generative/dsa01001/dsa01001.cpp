#include <iostream>
using namespace std;
void testCase();
int main() {
    // Your code here
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
    int n = s.length();
    int t = n - 1;
    while (t >= 0 && s[t] == '1') {
        t--;
    }
    if (t < 0) {
        for (int i = 0; i < n; i++) {
            cout << '0';
        }
        return;
    }
    s[t] = '1';
    for (int i = t + 1; i < n; i++) {
        s[i] = '0';
    }
    for (int i = 0; i < s.size(); i++ ) {
        cout << s[i];
    }
}
