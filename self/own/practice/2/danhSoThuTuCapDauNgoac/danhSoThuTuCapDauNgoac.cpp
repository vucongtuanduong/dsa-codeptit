#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    getline(cin, s);
    stack<int> st;
    int count = 1;
    vector<int> res;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            res.push_back(count);
            st.push(count++);
        } else if (!st.empty() && s[i] == ')') {
            res.push_back(st.top());
            st.pop();
        }
    }
    for (int x : res) {
        cout << x << " ";
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
