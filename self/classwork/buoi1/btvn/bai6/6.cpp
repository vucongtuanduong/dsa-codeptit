#include <bits/stdc++.h>
using namespace std;
void testCase();
bool isIncreasing(string s);
bool isDecreasing(string s);
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    // testCase();
    return 0;
}
bool isIncreasing(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] > s[i + 1]) {
            return false;
        }
    }
    return true;

}
bool isDecreasing(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] < s[i + 1]) {
            return false;
        }
    }
    return true;

}
void testCase() {
    string s;
    cin >> s;
    if (isIncreasing(s) || isDecreasing(s)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}