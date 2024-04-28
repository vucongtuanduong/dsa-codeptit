#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++){ 
        bool operator_found = false;
        if (s[i] != ')') {
            st.push(s[i]);
        } else {
            while (st.top() != '(') {
                char c = st.top();
                // cout << "c : " << c << endl;
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    operator_found = true;
                }
                st.pop();
            }
            // cout << "st.top(): " << st.top() << " , operator_found: " << operator_found << endl;
            st.pop();
            if (!operator_found) {
                return true;
            }
        }
    }
    return false;
}
void testCase() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            s.erase(s.begin() + i);
        }
    }
    // cout << "s: " << s << endl;
    if (check(s)) {
        cout << "Yes";
    } else {
        cout << "No";
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
