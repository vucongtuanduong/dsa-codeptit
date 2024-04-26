#include <bits/stdc++.h>
using namespace std;
int calPostFix(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i])) {
            // cout << "not digit: "  << s[i] << endl;
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int res = 0;
            switch(s[i]) {
                case '+':
                    res = op2 + op1;
                    break;
                case '-':
                    res = op2 - op1;
                    break;
                case '*':
                    res = op2 * op1;
                    break;
                case '/':
                    res = op2 / op1;
                    break;
            }
            st.push(res);
        } else {
            // cout << "is digit: " << s[i] << endl;
            st.push(s[i] - '0');
        }
    }
    return st.top();
}
void testCase() {
    string s;
    cin >> s;
    // cout << s << endl;
    cout << calPostFix(s);
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