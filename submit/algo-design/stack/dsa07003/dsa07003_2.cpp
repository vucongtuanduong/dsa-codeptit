#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            s.erase(s.begin() + i);
        }
    }
    // cout << s << endl;
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < s.size(); i++ ) {
        
        if (s[i] != ')') {
            st.push(s[i]);
            // cout << "push into stack: " << s[i] << endl;
        } else {
            bool hasOp = false;
            // cout << "IN stack: \n";
            while (!st.empty() && st.top() != '(') {
                // cout << st.top() << endl;
                char c = st.top();
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    hasOp = true;   
                    // cout << "hasOp = true \n";
                }
                st.pop();
            }
            st.pop();
            if (hasOp == false) {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
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
