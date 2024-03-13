#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
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
    int res = 1;
    for (int i = 0; i < s.size(); i++) {
        int l = i, r = i;
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                res = max(res, r - l + 1);
                l--;
                r++;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < s.size() - 1; i++) {
        int l = i, r = i + 1;
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                res = max(res, r - l + 1);
                l--;
                r++;
            } else {
                break;
            }
        }
    }
    cout << res;
}