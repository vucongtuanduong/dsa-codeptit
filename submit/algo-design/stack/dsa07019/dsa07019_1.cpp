#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    int a[n + 1], l[n + 1], r[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> st;

    for (int i = 1; i <= n; i++) {
        while(!st.empty() && a[i] <= a[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            l[i] = 1;
        } else {
            l[i] = st.top() + 1;
        }
        st.push(i);
    }
    stack<int> st1;
    for (int i = n; i >= 1; i--) {
        while (!st1.empty() && a[i] <= a[st1.top()]) {
            st1.pop();
        }
        if (st1.empty()) {
            r[i] = n;
        } else {
            r[i] = st1.top() - 1;
        }
        st1.push(i);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        long long temp = (long long) a[i] * (r[i] - l[i] + 1);
        res = max(temp, res);
    }
    cout << res;
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
