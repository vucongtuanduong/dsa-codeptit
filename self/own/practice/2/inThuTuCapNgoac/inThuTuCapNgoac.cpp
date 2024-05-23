#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    getline(cin, s);
    int n = s.size();
    s = " " + s;
    stack<int> st;
    vector<int> res;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            st.push(cnt);
            res.push_back(cnt);
            cnt++; 
        } else if (s[i] == ')') {
            int temp = st.top();
            st.pop();
            res.push_back(temp);
        }
    }
    for (auto x : res) {
        cout << x << " ";
    }
}
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
