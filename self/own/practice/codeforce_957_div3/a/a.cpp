#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int a, b ,c;
    cin >> a >> b >> c;
    for (int i = 1; i <= 5; i++) {
        int minNum = min({a, b, c});
        if (minNum == a) {
            a++;
        } else if (minNum == b) {
            b++;
        } else if (minNum == c) {
            c++;
        }
    }
    long long res = a * b * c;
    cout << res;
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
