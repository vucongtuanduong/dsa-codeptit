#include <bits/stdc++.h>
using namespace std;
bool isOpen(char c) {
    return (c == '(' || c == '[' || c == '{');
}
bool isMatched(char a, char b) {
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}
bool isBalanced(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        switch(s[i]) {
            case '(':
            case '[':
            case '{':
                st.push(s[i]);
                break;
            case ')':
                if (st.empty() || st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                }
                break;
            case ']':
                if (st.empty() || st.top() != '[') {
                    return false;
                } else {
                    st.pop();
                }
                break;
            case '}':
                if (st.empty() || st.top() != '{') {
                    return false;
                } else {
                    st.pop();
                }
                break; 
            default: continue;
        }
    }
    return st.empty();
}
void testCase() {
    string s;
    getline(cin, s);
    if (isBalanced(s)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline character after reading t
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}