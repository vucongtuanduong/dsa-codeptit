#include <bits/stdc++.h>
using namespace std;
void testCase();
long long mulBin(string s1, string s2);
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
long long mulBin(string s1, string s2) {
    long long x = 0, y = 0, res;
    for (int i = 0; i < s1.size(); i++) {
        x = x * 2 + (s1[i] - '0');
    }
    for (int i = 0; i < s2.size(); i++) {
        y = y * 2 + (s2[i] - '0');
    }
    res = x * y;
    return res;
}
void testCase() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << mulBin(s1, s2);
}