#include <iostream>
#include <stack>
using namespace std;
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
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }
    cout << st.size();
}