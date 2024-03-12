#include <iostream>
#include <stack>
using namespace std;
void testCase();
int main() {
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
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')' && !st.empty() && st.top() == '(') {//correct pair
            st.pop();
        } else if (s[i] == ')' && (st.empty() || st.top() == ')')) { //incorrect pair
            st.push(s[i]);
        }
    }
    //the stack now contain unbalanced brackets
    int open = 0, closing = 0;
    while (!st.empty()) {
        if (st.top() == '(') {
            open++;
        } else {
            closing++;
        }
        st.pop();
    }
    int ans = open / 2 + closing / 2; //moi cap dong mo nguoc chi can dao nguoc 1 dau
    ans += open  % 2 + closing % 2; //neu co cap ngoac trai huong, can dao ca 2
    cout << ans;
}