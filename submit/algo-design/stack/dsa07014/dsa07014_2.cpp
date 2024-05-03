#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void testCase() {
    string s;
    cin >> s;
    stack<int> st;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isOperator(s[i])) {
            st.push(s[i] - '0');
        } else {
            int op1 = st.top();st.pop();
            int op2 = st.top();st.pop();
            int res = 0;
            switch(s[i]) {
                case '+':
                    res = op1 + op2;
                    st.push(res);
                    break;
                case '-':
                    res = op1 - op2;
                    st.push(res);
                    break;
                case '*':
                    res = op1 * op2;
                    st.push(res);
                    break;
                case '/':
                    res = op1 / op2;
                    st.push(res);
                    break;
                
            }
        }
    }
    cout << st.top();
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
