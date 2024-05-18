#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while(!st.empty() && a[i] >= a[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            cout << i + 1 << " ";        
        } else {
            cout << i - st.top() << " ";
        }
        st.push(i);
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
