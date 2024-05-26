#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        string a = s.substr( l - 1, r - 1);
        string b = a;
        reverse(b.begin(), b.end());
        if (a== b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
