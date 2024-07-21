#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
    int n = s.size();
    if (n <= 9 || n >=18) {
        return false;
    }
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
int main() {
    // Write your code here
    string x;
    long long res = 0;
    while (cin >> x) {
        // cout << x << endl;
        if (check(x)) {
            res += stoll(x);
        }
    }
    cout << res;
    return 0;
}
