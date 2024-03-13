#include<bits/stdc++.h>
using namespace std;

bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

string postfixToPrefix(string s) {
    stack<string> st;
    int length = s.size();
    for (int i = 0; i < length; i++) {
        if (isOperator(s[i])) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = s[i] + op2 + op1;
            st.push(temp);
        } else {
            st.push(string(1, s[i]));
        }
    }
    return st.top();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << postfixToPrefix(s) << endl;
    }
    return 0;
}