#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void testCase() {
    string s;
    cin >> s;
    stack<string> st;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (!isOperator(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string new_op = s[i] + op2 + op1;
            st.push(new_op);
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
