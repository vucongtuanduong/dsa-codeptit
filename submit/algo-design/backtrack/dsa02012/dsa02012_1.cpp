#include <bits/stdc++.h>
using namespace std;
int res;
void testCase();
void Try(vector<vector<int>>a, int n, int m, int i, int j);
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
void Try(vector<vector<int>>a, int n, int m, int i, int j) {
    if (i == n - 1 && j == m - 1) {
        res++;
    } else {
        if (i < n - 1) {
            // cout << "Try(a, n, m, i + 1, j)\n";
            Try(a, n, m, i + 1, j);
        } 
        if (j < m - 1) {
            // cout << "Try(a, n, m,  i, j + 1)\n";
            Try(a, n, m,  i, j + 1);
            
        }
    }

}
void testCase() {
    int n, m;
    cin >> n >> m;
    res = 0;
    vector<vector<int>>a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    Try(a, n, m, 0, 0);
    cout << res;
}