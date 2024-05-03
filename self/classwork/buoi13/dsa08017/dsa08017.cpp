#include <bits/stdc++.h>
using namespace std;
void testCase() {
    queue<string> q;
    stack<string> st;
    int n;
    cin >> n;
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
