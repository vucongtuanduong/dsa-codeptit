#include <bits/stdc++.h>
using namespace std;
void testCase();
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
void testCase() {
    string s;
    cin >> s;
    stack<char> st;
    int n = s.size();
    // cout << s;
    for (int i = 0; i < n; i++) {
        if (!st.empty() && st.top() == '(' && s[i] == ')') {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    
    int open = 0, close = 0;
    while (!st.empty()) {
        char c = st.top();
        st.pop();
        if (c == '(') {
            open++;
        } else {
            close++;
        }
    }
    int res = (open + 1) / 2 + (close + 1)  / 2;
    cout << res;
}