#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>a(10, vector<int>(10));
vector<string>res;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
const string dir = "RLUD";
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
    for (int x = 0; x < 4; x++) {
        int nx = i + dx[x];
        int ny = j + dy[x];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 1)  {
            a[nx][ny] = 0;
            Try(nx, ny, s + dir[x]);
            a[nx][ny] = 1;
        }
    }
}
void testCase() {
    cin >> n;
    res.clear();
    // a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if (a[0][0] == 0 || a[n - 1][n - 1] == 0) {
        cout << "-1";
        return;
    }
    a[0][0] = 0;
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