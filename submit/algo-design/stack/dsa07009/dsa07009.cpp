#include <bits/stdc++.h>
using namespace std;
void testCase();
bool isOperator(char c);
string convert(string s);
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
bool isOperator(char c) {
    switch(c) {
        case '+':
        case '-':
        case '/':
        case '*':
        return true;
    }
    return false;
}
string convert(string s) {
    stack<string> st;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (isOperator(s[i])) {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        } else {
            st.push(string(1, s[i]));
        }

    }
    return st.top();
}
void testCase() {
    string exp;
    cin >> exp;
    cout << convert(exp);
}   