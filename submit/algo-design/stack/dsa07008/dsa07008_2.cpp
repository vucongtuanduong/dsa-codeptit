#include <bits/stdc++.h>
using namespace std;
int ranking(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-'){
        return 1;
    }
    return -1;
}
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    stack<char>st;
    string res = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (isalnum(s[i])) {
            res += s[i];
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                char c = st.top();
                st.pop();
                res += c;
            }
            st.pop();
        } else {
            while (!st.empty() && ranking(s[i]) <= ranking(st.top())) {
                char c = st.top();
                st.pop();
                res += c;
            }
            st.push(s[i]);
        }
        
    }
    while (!st.empty()) {
        char c = st.top();
        if (c != '(') {
            res += c;
        }
        st.pop();
    }
    cout << res;

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
