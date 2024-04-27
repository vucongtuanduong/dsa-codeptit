#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    return (c == '+' || )
}
void testCase() {
    string s;
    cin >> s;
    stack<char> st;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isOperator(s[i])) {
            st.push(s[i]);
        }
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
