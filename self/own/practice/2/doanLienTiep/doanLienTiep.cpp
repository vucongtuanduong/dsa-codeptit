#include <bits/stdc++.h>
using namespace std;
void testCase(){ 
    int n;
    cin >> n;
    int a[n];
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res[n];
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
