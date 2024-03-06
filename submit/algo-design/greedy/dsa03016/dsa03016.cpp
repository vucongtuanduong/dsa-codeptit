#include <bits/stdc++.h>
using namespace std;
void testCase();
void maxNum(int s, int d);
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
void testCase() {
    int s, d;
    cin >> s >> d;
    maxNum(s, d);
}
void maxNum(int s, int d) {
    int a[d];
    if (s > 9 * d || s == 0) {
        cout << (s == 0 && d == 1 ? "0" : "-1");
        return;
    }
    s--;
    for (int i = d- 1; i > 0; i--) {
        if (s >= 9) {
            a[i] = 9;
            s-= 9;
        } else {
            a[i] = s;
            s = 0;
        }
    }
    a[0] = s + 1;
    for (int i = 0; i < d; i++) {
        cout << a[i] ;
    }
}