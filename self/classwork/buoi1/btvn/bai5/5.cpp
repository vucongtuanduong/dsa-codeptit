#include <bits/stdc++.h>
using namespace std;
void testCase();
int main () {
    testCase();
    return 0;
}
void testCase() {
    string s;
    getline(cin, s);
    int c = s[s.size() - 1] - '0';
    int a = s[0] - '0';
    int b = s[4] - '0';
    // cout << a << " " << b << " " << c << endl;
    if (a + b == c) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}