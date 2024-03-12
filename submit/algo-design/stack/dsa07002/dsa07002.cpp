#include <iostream>
#include <stack>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int t;
    cin >> t;
    stack<int> st;
    while (t--) {
        string choice;
        cin >> choice;
        if (choice == "PUSH") {
            int x;
            cin >> x;
            st.push(x);
        } else if (choice == "POP") {
            if (!st.empty()) {
                st.pop();
            } else {
                continue;
            }
        } else if (choice == "PRINT") {
            if (!st.empty()) {
                cout << st.top() << endl;
            } else {
                cout << "NONE" << endl;
            }
        }
    }
}