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
    long long res = s[0] - '0';
    int n =s.size();
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            string temp = s.substr(j, i - j + 1);
            long long x = stoll(temp);
            res += x;

        }
    }
    cout << res;
}