#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    int next[n];
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[i] >= a[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            next[i] = -1;
        } else {
            next[i] = st.top();
        }
        st.push(i);


    }
    while (q--) {
        int x ;
        cin >> x;
        x--;
        int cnt = 0;
        while (x != -1) {
            
            x = next[x];
            cnt++;
        }
        cout << cnt - 1 << endl;
    }
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
