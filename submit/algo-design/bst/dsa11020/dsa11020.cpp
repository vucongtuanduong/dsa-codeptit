#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> se;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        se.insert(a[i]);
    }
    sort(b.begin(), b.end());
    if (a == b && se.size() == n) {
        cout << "1";
    } else {
        cout << "0";
    }
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
