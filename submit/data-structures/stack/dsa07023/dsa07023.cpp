#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
void testCase() ;
int main() {
    // Write your code here
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    stack<string> st;
    string temp;
    while (ss >> temp) {
        st.push(temp);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}