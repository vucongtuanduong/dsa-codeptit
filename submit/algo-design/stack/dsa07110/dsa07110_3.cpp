#include <bits/stdc++.h>
using namespace std;
bool isOpen(char c) {
    return (c == '(' || c == '[' || c == '{');
}
bool isMatched(char a, char b) {
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    for (int i = 0;i < n; i++) {
        if (isOpen(s[i])) {
            st.push(s[i]);
        } else {
            if (st.empty() || !isMatched(st.top(), s[i])) {
                cout << "NO";
                return;
            }
            st.pop();
        }
    }
    cout << "YES";
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
