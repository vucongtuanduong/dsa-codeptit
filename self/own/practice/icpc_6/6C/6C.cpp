#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    int n;
    cin >> n;
    int a[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    int count = 0;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && a[i] <= st.top()) {
            st.pop();
        }
        if (st.empty()) {
            count++;
        }
        st.push(a[i]);

    }
    cout << count;
    return 0;
}
