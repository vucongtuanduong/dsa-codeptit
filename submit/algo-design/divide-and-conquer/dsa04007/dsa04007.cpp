#include <bits/stdc++.h>
using namespace std;
void testCase();
int base10(int x, int k);
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
int base10(int x, int k) {
    int sum = 0;
    string s = to_string(x);
    for (int i = 0; i < s.size(); i++) {
        sum = sum * k + s[i] - '0';
    }
    return sum;
}
void testCase() {
    int k;
    string a, b;
    cin >> k >> a >> b;
    while (a.size() < b.size()) {
        a = "0" + a;
    }
    while (b.size() < a.size()) {
        b = "0" + b;
    }
    string s = "";
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int temp = (a[i] - '0') + (b[i] - '0') + carry;
        s = char(temp % k + '0') + s;
        carry = temp / k;
    }
    if (carry > 0) {
        s = char(carry + '0') + s;
    }
    cout << s;
}