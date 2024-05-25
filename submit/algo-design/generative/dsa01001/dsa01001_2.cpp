#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    int i = n -1;
    while (i > 0 && s[i] == '1') {
        s[i] = '0';
        i--;
    }
    if (i == 0) {
        for (int j = 0; j < n; j++) {
            cout << "0";
        }
        return;
    }
    s[i] = '1';
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
