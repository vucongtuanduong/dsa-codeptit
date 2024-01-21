#include <bits/stdc++.h>
using namespace std;
void testCase();
void tolower(string &s);
void toupper(char &c);
int main () {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
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
void testCase() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string temp;
    string res = "";
    while (ss >> temp) {
        tolower(temp);
        toupper(temp[0]);
        res += temp + " ";
    }
    res.pop_back();
    cout << res;
}