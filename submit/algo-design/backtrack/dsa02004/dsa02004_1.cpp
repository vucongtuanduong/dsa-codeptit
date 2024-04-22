#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> a;
vector<string> res;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
string ds = "RDUL";
void testCase();
void Try(int i, int j, string s);
int main() {
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
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && a[nx][ny] == 1) {
            a[nx][ny] = 0;
            Try(nx, ny, s + ds[x]);
            a[nx][ny] = 1;
        }
    }
}
void testCase() {
    cin >> n;
    a.resize(n, vector<int>(n));
    res.clear();
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
    if (res.empty()) {
        cout << "-1";
        return;
    }
    sort(res.begin(), res.end());
    for (string path : res) {
        cout << path << " ";
    }
    // Optionally, you can clear the result vector here
    res.clear();
}
