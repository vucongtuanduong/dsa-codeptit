#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    stack<string> st;
    for (int i = n - 1; i >= 0; i--) {
        if (isOperator(s[i])) {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string newOp = op1 + op2 + s[i];
            st.push(newOp);
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
