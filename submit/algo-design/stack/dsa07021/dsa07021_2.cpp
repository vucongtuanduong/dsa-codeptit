#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    int maxLength = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (!st.empty()) {
                maxLength = max(maxLength, i - st.top());
            } else {
                st.push(i);
            }
        }
    }
    cout << maxLength;
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
