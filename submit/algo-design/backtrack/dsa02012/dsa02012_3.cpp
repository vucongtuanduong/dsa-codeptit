#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>a;
vector<string>res;
void testCase();
void Try(int i, int j, string s);
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
void Try(int i, int j, string s) {
    if (i == n - 1 && j == n - 1) {
        res.push_back(s);
        return;
    }
    if (i + 1 < n && a[i + 1][j] == 1) {
        Try(i + 1, j, s + "D");
    } 
    if (j + 1 < n && a[i][j + 1] == 1) {
        Try(i, j + 1, s + "R");
    }
}
void testCase() {
    cin >> n;
    res.clear();
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
    if (res.size() == 0) {
        cout << "-1";
    } else {
        sort(res.begin(), res.end());
        for (auto x : res) {
            cout << x << " ";
        }
    }
}