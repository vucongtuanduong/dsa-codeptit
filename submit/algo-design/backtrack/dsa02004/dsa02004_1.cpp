#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
string s;
vector<string>res;
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
    cin >> n;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if (a[0][0] == 0 || a[n - 1][n - 1] == 0) {
        cout << "-1";
        return;
    }
    Try(0, 0, "");
}