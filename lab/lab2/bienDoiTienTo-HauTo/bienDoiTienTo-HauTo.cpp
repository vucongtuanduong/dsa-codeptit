#include <bits/stdc++.h>
using namespace std;
const string operations = "+-*/";
string preFixtoPostFix(string s) {
    string res = "";
    stack<string> st;
    // cout << s << endl;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--){ 
        if (operations.find(s[i]) != -1) {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string new_op = op1 + op2 + s[i];
            // cout << "op1: " << op1 << ", op2: " << op2 << ", new_op: " << new_op << endl;
            st.push(new_op);
        } else {
            st.push(string(1, s[i]));
        }
    }
    
    return st.top();
}
void testCase() {
    string s;
    cin >> s;
    // cout << s << endl;
    cout << preFixtoPostFix(s);
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
