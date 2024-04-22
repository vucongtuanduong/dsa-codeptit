#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while( t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int k;
    cin >> k;
    string a, b;
    cin >> a >> b;
    while (a.size() < b.size()) {
        a = "0" + a;
    }
    while (b.size() < a.size()) {
        b = "0" + b;
    }
    string res = "";
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int temp = (a[i] - '0') + (b[i] - '0') + carry;
        res = to_string(temp % k) + res;
        carry = temp / k;
    }
    if (carry > 0) {
        res = to_string(carry) + res;
    }
    cout << res;
}