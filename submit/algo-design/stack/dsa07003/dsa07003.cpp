#include <iostream>
#include <stack>
using namespace std;
void testCase();


int main() {
    // Write your code here
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    string s;
    getline(cin, s);
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != ')') {
            st.push(s[i]);
        } else {
            bool ok = false;
            while (!st.empty()) {
                char c = st.top();
                st.pop();
                if (c == '(') {
                    break;
                }
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    ok = true;
                }
            }
            if (!ok) {
                cout << "Yes";
                return;
            }
        }
        
    }
    cout << "No";
    
}