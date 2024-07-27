#include <bits/stdc++.h>
using namespace std;
bool isOpen(char c) {
    return (c == '(' || c == '[' || c == '{');
}
bool isValidPair(char a, char b) {
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}
void testCase() {
    string s;
    getline(cin, s);
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (isOpen(s[i])) {
            // cout << "0";
            st.push(s[i]);
        } else if (st.empty() || !isValidPair(st.top(), s[i])) {
            // cout << "1";
            cout << "false";
            return;
        } else if (!st.empty() && isValidPair(st.top(), s[i])){
            // cout << "2";
            st.pop();
        }
    }
    if (!st.empty()) {
        // cout << "4";
        cout << "false";

    } else {
        cout << "true";
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
