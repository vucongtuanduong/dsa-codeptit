#include <bits/stdc++.h>
using namespace std;
void testCase();
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int last = n % 10;
    int first = 0;
    while (n > 0) {
        first = n % 10;
        n /= 10;
    }
    if (first == last) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}