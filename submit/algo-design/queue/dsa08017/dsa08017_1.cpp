#include <bits/stdc++.h>
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
    int n;
    cin >> n;
    queue<string> q;
    stack<string> st;
    q.push("");
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        st.push(s);
        if (s.size() == n) {
            continue;
        }
        q.push(s + "6");
        q.push(s + "8");
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

}