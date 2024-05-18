#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    return (c == '+' || c == '*' || c == '-' || c == '/');
}
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    stack<string> st;
    for (int i = 0; i < n; i++) {
        if (!isOperator(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string newOp = "(" + op2 + s[i] + op1 + ")";
            st.push(newOp);
        }
    }
    cout << st.top();
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
