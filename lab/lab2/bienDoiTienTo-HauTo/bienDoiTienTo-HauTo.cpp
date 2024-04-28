#include <bits/stdc++.h>
using namespace std;
const string operations = "+-*/";
string preFixtoPostFix(string s) {
    stack<string> st;
    for (int i = 0; i < s.size(); i++){ 
        if (operations.find(s[i]) != -1) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string new_op = op2 + s[i] + op1;
            cout << "new_op: " << new_op << endl;
            
        }
    }
    return "";
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
