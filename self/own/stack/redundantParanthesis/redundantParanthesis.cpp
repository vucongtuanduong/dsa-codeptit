#include <bits/stdc++.h>
using namespace std;
bool checkRedundant(string s) {
    stack<char> st;
    for (char c : s) {
        if (c != ')') {
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
    cin >> s;
    if (checkRedundant(s)) {
        cout << "Contains redundant paranthesis";
    } else {
        cout << "Not contain redundant paranthesis";
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
