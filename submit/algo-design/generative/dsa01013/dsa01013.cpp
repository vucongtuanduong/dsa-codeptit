#include <iostream>
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
    string res = "";
    res += s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            if (res[i - 1] == '0') {
                res += '1';
            } else if (res[i - 1] == '1') {
                res += '0';
            }
        } else {
            res += res[i - 1];
        }
    }
    cout << res;
}