#include <bits/stdc++.h>
using namespace std;
bool isOpen(char c) {
    return (c == '(' || c == '{' || c == '{');
}
bool isMatched(char a, char b) {
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}
bool isBalanced(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (isOpen(s[i])) {
            st.push(s[i]);
        } else if (!isalpha(s[i]) && s[i] != ' ') {
            if (st.empty() || !isMatched(st.top(), s[i])) {
                return false;
            }
        }
    }
    if (st.empty()) {
        return true;
    }
    return false;
}
void testCase() {
    string s;
    cin >> s;
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
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
