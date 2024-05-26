#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
void testCase() {
    cin >> n;
    a.resize(n, vector<int>(n));
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t-- ) {
        testCase();
        cout << endl;
    }
    return 0;
}
