#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        stack<char> st;
        int cnt = 0;
        for (char c : S) {
            if (c == '(') {
                st.push(c);
            } else if (!st.empty()) {
                st.pop();
            } else {
                cnt++;
            }
        }
        cnt += st.size() / 2;
        cout << cnt << endl;
    }
    return 0;
}