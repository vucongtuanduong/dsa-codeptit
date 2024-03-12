#include <iostream>
using namespace std;
void testCase() ;
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
    int n = s.size();
    int i = n - 1;
    while (i >= 0 && s[i] == '0') {
        i--;
    }
    s[i] = '0';
    for (int j = i + 1; j < n; j++) {
        s[j] = '1';
    }
    if (i == -1) {
        for (int i = 0; i < n; i++) {
            cout << '1';
        }
        return;
    }
    cout << s;
}
