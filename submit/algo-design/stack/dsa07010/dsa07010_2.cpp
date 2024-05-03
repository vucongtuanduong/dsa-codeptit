#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void testCase() {
    string s;
    cin >> s;
    stack<string> st;
    string res = "";
    int n = s.size();
    for (int i = n; i >= 0; i--) {
        if (!isOperator(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string new_op = op1 + op2 + s[i];
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
