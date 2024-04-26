#include <bits/stdc++.h>
using namespace std;
bool checkRedundant(string s) {
    stack<char> st;
    for (char c : s) {
        if (c != ')' && c != ' ') {
            st.push(c);
        } else {
            bool operator_found = false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operator_found = true;
                }
                st.pop();
            }
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
    // cout << s << ": ";
    if (checkRedundant(s)) {
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
