#include <bits/stdc++.h>
using namespace std;
void testCase();
void toupper(char &c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
}
void tolower(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }

}
int main () {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        testCase();
        cout << endl;
    }
    // testCase();
    return 0;
}
void testCase() {
    string s;
    getline(cin, s);
    // cout << s << endl;
    stringstream ss(s);
    string temp;
    vector<string> res;
    while (ss >> temp) {
        tolower(temp);
        res.push_back(temp);
    }
    
    for (int i = 1; i < res.size(); i++) {
        toupper(res[i][0]);
        cout << res[i];
        if (i != res.size() - 1) {
            cout << " ";
        } else {
            cout << ", ";
        }
    }
    for (int i = 0; i < res[0].size(); i++) {
        toupper(res[0][i]);
    }
    cout << res[0];
    
}