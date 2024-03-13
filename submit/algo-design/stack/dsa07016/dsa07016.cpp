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
    for (int i = 0; i <= s.size(); i++) {
        st.push(i + 1);
        if (i == s.size() || s[i] == 'I') {
            while (!st.empty()) {
                int x = st.top();
                cout << x;
                st.pop();
            }
        }
    }
}