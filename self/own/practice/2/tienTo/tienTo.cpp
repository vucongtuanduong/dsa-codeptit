#include <bits/stdc++.h>
using namespace std;
bool isOperator(string c) {
    return (c == "+" || c == "-" || c == "*" || c == "/");
}
void testCase() {
    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    stack<long long> st;
    for (int i = n - 1; i >= 0; i--) {
        if (!isOperator(input[i])) {
            // cout << input[i] << endl;
            st.push(stoll(input[i]));
        } else {
            long long op1 = st.top();st.pop();
            long long op2 = st.top();st.pop();
            if (input[i] == "+") {
                long long res = op1 + op2;
                st.push(res);
            } else if (input[i] == "-") {
                long long res = op1 - op2;
                st.push(res);
            } else if (input[i] == "*") {
                long long res = op1 * op2;
                st.push(res);
            } else if (input[i] == "/") {
                long long res = op1 / op2;
                st.push(res);
            }
        }
    }
    cout << st.top();
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
