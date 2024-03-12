#include <bits/stdc++.h>
using namespace std;
void testCase();
void findSubset(string s, string &res, int start);
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
void findSubset(string s, string &res, int start) {
    for (int i = start; i < s.size(); i++) {
        res.push_back(s[i]);
        cout << res << " ";
        findSubset(s, res, i + 1);
        res.pop_back();
    }
}
void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string res = "";
    findSubset(s, res, 0);
}