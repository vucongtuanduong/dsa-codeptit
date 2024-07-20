#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    int n = s.length();
    set<int> numChar;
    for (int i = 0; i < n; i++) {
        numChar.insert(s[i]);
    }
    int lim = numChar.size();
    int l = 0, r = 0, len = 0;
    map<char,int> mp;
    int res = INT_MAX;
    while (r < n) {
        char c = s[r];
        mp[c]++;
        if (numChar.count(c) == 1 && mp[c] == 1) {
            len++;
        }
        while (l <= r && len == lim) {
            char d = s[l];
            mp[d]--;
            res = min(res, r - l + 1);
            if (numChar.count(d) == 1 && mp[d] == 0) {
                len--;
            }
            l++;
        }
        r++;
    }
    cout << res;
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
