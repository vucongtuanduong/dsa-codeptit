#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    cin >> s;
    stack<int> st;
    int n = s.size();
    for (int i = 0; i <= n; i++) {
        st.push(i + 1);
        if (i == n || s[i] == 'I') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
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
