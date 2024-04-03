#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<
void testCase();
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
    int n, x;
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}