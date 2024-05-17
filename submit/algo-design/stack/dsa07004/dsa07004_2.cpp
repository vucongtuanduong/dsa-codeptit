#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    for (int i =0 ; i < n; i++) {
        if (!st.empty() && st.top() == '(' && s[i] == ')') {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    int open = 0, close = 0;
    while (!st.empty()) {
        char c = st.top();
        if (c == '(') {
            open++;
        } else {
            close++;
        }
        st.pop();
    }
    int res = (open + 1) /2 + (close + 1) / 2;
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
