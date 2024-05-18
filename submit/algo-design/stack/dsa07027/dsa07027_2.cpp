#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;//store index;
    int res[n];
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            res[i] = -1;
        } else {
            res[i] = a[st.top()];
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
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
