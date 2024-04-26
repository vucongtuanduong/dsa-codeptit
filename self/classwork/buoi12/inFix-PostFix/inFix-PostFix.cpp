#include <bits/stdc++.h>
using namespace std;
int countRank(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return -1;
}
string inFixtoPostFix(string s) {
    stack<char> st;
    string out = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (isalnum(s[i])) {
            out += s[i];
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                char c = st.top();
                st.pop();
                out += c;
            }   
            st.pop();
        } else {
            while (!st.empty() && (countRank(s[i]) <= countRank(st.top()))) {
                char c = st.top();
                st.pop();
                out += c;
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        char c = st.top();
        if (c != '(') {
            out += c;
            
        }
        st.pop();
    }
    return out;
}
void testCase() {
    string s;
    cin >> s;
    // cout << s << endl;
    cout << inFixtoPostFix(s);
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
