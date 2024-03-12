#include <bits/stdc++.h>
using namespace std;
void testCase();
int convert(string s);
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
int convert(string s) {
    stack<int> st;

    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (isOperator(s[i])) {
            int op1 = st.top();st.pop();
            int op2 = st.top();st.pop();
            switch(s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
            }
        } else {
            st.push(s[i] - '0');
        }
    }
    return st.top();
}
void testCase() {
    string s;
    cin >> s;
    cout << convert(s);
}