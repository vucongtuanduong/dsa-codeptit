#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main() {
    // Write your code here
    stack<int> st;
    for (int i = 0; i < 5; i++) {
        st.push(i * 2);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}
