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
    stack<int> st;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
            st.push(i);
        } else {
            if (!st.empty()) {
                st.pop();
            } else {
                int j = i;
                while (s[j] == ']') {
                    j++;
                }
                swap(s[i], s[j]);
                res += j - i;
                st.push(i);
            }
        }
    }
    cout << res;
}