#include<bits/stdc++.h>
using namespace std;

void testCase();
string postfixToPrefix(string s);
bool isOperator(char c);
int main() {
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
bool isOperator(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}
string postfixToPrefix(string s) {
    stack<string> st;
    int length  = s.size();
    for (int i = 0; i < length; i++) {
        if (isOperator(s[i])) {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = s[i] + op2 + op1;
            st.push(temp);
        } else {
            st.push(string(1, s[i]));
        }
    }
    return st.top();
}
void testCase() {
    string s;
    cin >> s;
    cout << postfixToPrefix(s);
}