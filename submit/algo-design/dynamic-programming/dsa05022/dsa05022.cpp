#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> dp(n + 1, INT_MAX);
    for (int i = 0; i < n; i++) {
        
    }
}