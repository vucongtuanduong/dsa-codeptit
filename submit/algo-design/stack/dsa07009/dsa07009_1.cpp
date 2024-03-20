#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c);
void testCase();
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
void testCase() {
    string s;
    cin >> s;
    stack<string> st;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        
        if (isOperator(s[i])) {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        } else {
            st.push(string(1, s[i]));
        }
    }
    cout << st.top();
}
bool isOperator(char c){
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}