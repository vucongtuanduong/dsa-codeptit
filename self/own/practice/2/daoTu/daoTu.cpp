#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> v;
    while (ss >> s) {
        reverse(s.begin(), s.end());
        v.push_back(s);
    }
    for (string s : v) {
        cout << s << " ";
        // st.pop();
    }
}
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
