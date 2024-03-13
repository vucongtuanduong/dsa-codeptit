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

string postfixToInfix(string s) {
    stack<string> st;
    int length = s.size();
    for (int i = 0; i < length; i++) {
        if (isOperator(s[i])) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "(" + op2 + s[i] + op1 + ")";
            st.push(temp);
        } else {
            st.push(string(1, s[i]));
        }
    }
    return st.top();
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << postfixToInfix(s) << endl;
    }
    return 0;
}