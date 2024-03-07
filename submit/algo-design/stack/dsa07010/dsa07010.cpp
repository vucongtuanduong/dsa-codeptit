#include <bits/stdc++.h>
using namespace std;
void testCase();
string convert(string s);
bool isOperator(char x);
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
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}
string convert(string s) {
    stack<string> st;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (isOperator(s[i])) {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string temp = op1 + op2 + s[i];
            st.push(temp);
        } else {
            st.push(string(1, s[i]));
        }
    }
    return st.top();
}
void testCase() {
    string s;
    cin >> s;
    cout << convert(s);
}