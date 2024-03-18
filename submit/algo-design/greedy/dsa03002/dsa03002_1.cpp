#include <bits/stdc++.h>
using namespace std;
void testCase();
long long minChange(string s);
long long maxChange(string s);
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    string s1, s2;
    cin >> s1 >> s2;
    long long min = minChange(s1) + minChange(s2);
    long long max = maxChange(s1) + maxChange(s2);
    cout << min << " " << max;
}
long long minChange(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '6') {
            s[i] = '5';
        }
    }
    return stoll(s);
}
long long maxChange(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '5') {
            s[i] = '6';
        }
    }
    return stoll(s);
}