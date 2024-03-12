#include <iostream>
#include <algorithm>
using namespace std;
void testCase();
void testCase2();
void findMaxNumber(string &s, int k, string &res);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase2();
        cout << endl;
    }
    return 0;
}
void testCase2() {
    int k;
    string s;
    cin >> k >> s;
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
void findMaxNumber(string &s, int k, string &res) {
    if (k == 0) {
        return;


    }
    int x = s.size();
    for (int i = 0; i < x - 1; i++) {
        for (int j = i + 1; j < x; j++) {
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                if (s.compare(res) > 0) {
                    res = s;
                    findMaxNumber(s, k - 1, res);
                }
                swap(s[i], s[j]);
            }
        }   
    }
}
void testCase() {
    //WA
    int k;
    string s;
    cin >> k >> s;
    string res = s;
    findMaxNumber(s, k, res);
    cout << res;
}