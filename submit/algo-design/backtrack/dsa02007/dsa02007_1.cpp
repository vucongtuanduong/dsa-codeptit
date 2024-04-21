#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (k == 0) {
            break;
        }
        char c = '0';
        for (int j = i + 1; j < s.size(); j++) {
            c = max(c, s[j]);
        }
        if (c <= s[i]) {
            continue;
        }
        string newNumber = s;
        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] == c) {
                string temp = s;
                swap(temp[i], temp[j]);
                newNumber = max(newNumber, temp);
            }
        }
        s = newNumber;
        k--;
    }
    cout << s;
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
