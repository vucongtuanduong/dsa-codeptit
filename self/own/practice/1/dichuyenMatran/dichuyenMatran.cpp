#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, 1};

int dy[] = {0, 1, 1};
int n, m, res;
vector<vector<int>> a;
void testCase();
void Try(int i, int j);
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
void Try(int i, int j) {
    if (i == n - 1 && j == m - 1) {
        res++;
        return;
    }
    for (int x = 0; x < 3; x++) {
        int nx = i + dx[x];
        int ny = j + dy[x];
        if (nx < n && ny < m) {
            int diff = abs(a[nx][ny] - a[i][j]);
            int newx = nx + diff;
            int newy = ny + diff;
            if (newx < n && newy < m) {
                Try(nx, ny);  // Change from Try(newx, newy) to Try(nx, ny) here
            }
        }
    }
}
void testCase() {
    res = 0;
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    Try(0, 0);
    cout << res << endl;
}
