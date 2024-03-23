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
    int n = s.size();
    int i = n - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '1';
        i--;
    }
    if (i >= 0) {
        s[i] = '0';
        cout << s;
        return;
    } else {
        for (int j = 0; j < n; j++) {
            cout << "1";
        }
    }
    
}