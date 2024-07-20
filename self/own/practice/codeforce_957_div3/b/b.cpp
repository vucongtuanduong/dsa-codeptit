#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.pop_back();
    long long res = 0;
    for (int x : a) {
        res += (x - 1) + x;
    }
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
