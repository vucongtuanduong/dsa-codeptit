#include <bits/stdc++.h>
using namespace std;
// y tuong, tai 1 vi tri tim ra diem gan nhat, gia tri lon nhat nho hon no
void testCase();
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
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
    int a[n + 1], l[n + 1], r[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    for(int i=  1; i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            l[i] = 1;
        } else {
            l[i] = st.top() + 1;
        }
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            r[i] = n;
        } else {
            r[i] = st.top() - 1;
        }
        st.push(i);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        long long s = (long long) a[i] * (r[i] - l[i] + 1);
        res = max(res, s);
    }
    cout << res;

}