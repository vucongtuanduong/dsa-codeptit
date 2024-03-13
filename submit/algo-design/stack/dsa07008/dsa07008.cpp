#include <bits/stdc++.h>
using namespace std;
void testCase();
string infixToPostfix(string s);
int precedence(char op) ;
int main() {
    // Write your code here
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
int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return -1;
}
string infixToPostfix(string s) {
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}
void testCase() {
    string s;
    cin >> s;
    cout << infixToPostfix(s);
}