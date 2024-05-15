#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    stack<string> st;
    queue<string> q;
    q.push("6");
    q.push("8");
    while (!q.empty()) {
        string s = q.front();
        st.push(s);
        q.pop();
        if (s.size() < n) {
            q.push(s + "6");
            q.push(s + "8");
        } 
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
