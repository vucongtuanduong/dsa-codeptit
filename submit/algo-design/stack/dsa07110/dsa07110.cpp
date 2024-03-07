#include <bits/stdc++.h>
using namespace std;
void testCase();
bool isMatching(char a, char b) {
    if ((a == '(') && (b == ')') || (a == '[') && (b == ']') || (a == '{') && (b == '}')) {
        return true;
    }  else {
        return false;
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
void testCase() {
    string s;
    cin >> s;
    stack<char>st;
    bool isBalanced = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else if (st.empty() || !isMatching(st.top(), s[i])) { // Corrected here
            isBalanced = false;
            break;
        } else {
            st.pop(); // Moved inside the else if condition
        }
    }
    if (!st.empty()) {
        isBalanced  = false;
    }
    if (isBalanced == false) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}