#include <bits/stdc++.h>
using namespace std;
void testCase();
bool isOperator(char c);
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
bool isOperator(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (isOperator(s[i])) {
            int op1 = (st.top());st.pop();
            int op2 = (st.top());st.pop();
            int res ;
            switch(s[i]) {
                case '+':
                    res = op1 + op2 ;
                    st.push(res);
                    break;
                case '-':
                    res = op2 - op1;
                    st.push(res);
                    break;
                case '*':
                    res = op1 * op2;
                    st.push(res);
                    break;
                case '/':
                    res = op2 / op1;
                    st.push(res);
                    break;
            }
        } else {
            st.push(s[i] - '0');
        }
    }
    
    cout << st.top();
}