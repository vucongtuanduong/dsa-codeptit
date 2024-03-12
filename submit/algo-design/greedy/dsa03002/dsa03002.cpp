#include <iostream>
using namespace std;
void testCase();
string minNum(string s);
string maxNum(string s);
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    string s1, s2;
    cin >> s1 >> s2;
    long long maxRes = stoll(maxNum(s1)) + stoll(maxNum(s2));
    long long minRes = stoll(minNum(s1)) + stoll(minNum(s2));
    
    cout << minRes << " " << maxRes;
}
string minNum(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '6') {
            s[i] = '5';
        }
    }
    return s;
}
string maxNum(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '5') {
            s[i] = '6';
        }
    }
    return s;
}