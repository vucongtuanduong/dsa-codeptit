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
    for (int i = n - 1; i >= 0; i--) {
        if (isOperator(s[i])) {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string new_op = "(" + op1 + s[i] + op2 + ")";
            st.push(new_op);
        } else {
            st.push(string(1, s[i]));
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
