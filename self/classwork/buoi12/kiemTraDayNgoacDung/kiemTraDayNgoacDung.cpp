#include <bits/stdc++.h>
using namespace std;
bool isOpen(char c) {
    return (c == '(' || c == '[' || c == '{') ;
}
bool isMatch(char a, char b) {
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}
bool check(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++){ 
        if (isOpen(s[i])) {
            st.push(s[i]);
        } else {
            if (st.empty() || !isMatch(st.top(), s[i])) {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return st.empty();
}
void testCase() {
    string s;
    cin >> s;
    if (check(s)) {
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