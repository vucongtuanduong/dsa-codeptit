#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){ 
        cin >> a[i];
    }
    stack<int> st;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            res[i] = i + 1;
        } else {
            res[i] = i - st.top();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++ ) {
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
