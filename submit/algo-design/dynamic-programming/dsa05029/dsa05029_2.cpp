#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int dp(int index) {
    if (index == n) {
        return 1;
    }
    int res = 0;
    if (s[index] >= '1' && s[index] <= '9') {
        res += dp(index + 1);
    }
    if (index + 1 < n && (s[index] == '1')) {
        res += dp(index + 2);
    }
    if (index + 1 < n && (s[index] == '2' && s[index + 1] <= '6')) {
        res += dp(index + 2);
    }
    return res;
}
void testCase() {
    
    cin >> s;
    n = s.size();
    cout << dp(0);
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
