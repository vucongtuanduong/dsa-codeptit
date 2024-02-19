// https://code.ptit.edu.vn/student/question/DSA07003
// KIỂM TRA BIỂU THỨC SỐ HỌC

#include <bits/stdc++.h>
using namespace std;

void testCase() {
    string s; getline(cin, s);
    cout << s << endl;
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(')
            st.push(s[i]);
        else {
            st.pop();
        }
    }
    if (!st.empty()) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 1; cin >> T; cin.ignore();
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}

// 3
// ((a+b))
// (a + (b)/c)
// (a + b*(c-d))