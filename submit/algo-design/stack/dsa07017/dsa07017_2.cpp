#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    int a[n + 1] , le[n + 1], gr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    for (int i = n; i >= 1; i--){ 
        while (!st.empty() && a[i] >= a[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            gr[i] = -1;
        } else {
            gr[i] = st.top();
        }
        st.push(i);
    }
    stack<int> st2;
    for (int i = n; i >= 1; i--){ 
        while (!st2.empty() && a[i] <= st2.top()) {
            st2.pop();
        }
        if (st2.empty()) {
            le[i] = -1;
        } else {
            le[i] = st2.top();
        }
        st2.push(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (gr[i] == -1) {
            cout << "-1 ";
        } else {
            cout << le[gr[i]] << " ";
        }
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
