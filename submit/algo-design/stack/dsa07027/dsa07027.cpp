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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            res[i] = -1;
        } else {
            res[i] =  st.top();
        }
        st.push(a[i]);
        
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    
}