#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    queue<string> q;
    stack<string> st;
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
    cout << st.size() << endl;
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
