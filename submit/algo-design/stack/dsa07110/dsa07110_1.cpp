#include <bits/stdc++.h>
using namespace std;
bool isMatched(char a, char b) {
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}
void testCase() {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++ ) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty() || !isMatched(st.top(), s[i])) {
                cout << "NO";
                return;

            }
            st.pop();
        }
    }
    cout << "YES";
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
