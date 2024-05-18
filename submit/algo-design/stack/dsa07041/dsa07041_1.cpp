#include <bits/stdc++.h>
using namespace std;
bool isOpen(char c) {
    return (c == '(');
}
void testCase() {
    string s;
    cin >> s;
    stack<char> st;
    int  n = s.size();
    for (int i = 0; i < n; i++) {
        if (isOpen(s[i])) {
            st.push(s[i]);
        } else {
            if (!st.empty() && st.top() == '(') {
                st.pop(); 
            } else {
                st.push(s[i]);
            }
            
        }
    }
    cout << n - st.size();
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
