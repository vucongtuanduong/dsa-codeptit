#include <bits/stdc++.h>
using namespace std;
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
int n, m;
vector<vector<int>> a;
void testCase() {
    cin >> n >> m;
    a.resize(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    } 
    int f[n][m];
    memset(f, 0, sizeof(f));
    queue<pair<int,int>> q;
    q.push({0, 0});
    int res = -1;
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        if (current.first == n - 1 && current.second == m - 1) {
            res = f[n - 1][m - 1];
            break;
        }
        for (int k = 0; k < 3; k++)  {
            int x = current.first + dx[k];

            int y = current.second + dy[k];
            int len = 0;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                len = abs(a[x][y] - a[current.first][current.second]);
            }
            if (len > 0) {
                int nx = current.first + dx[k] * len;
                int ny = current.second + dy[k] * len;
                if (nx >= 0 && nx < n && ny >= 0 && y < m && !f[nx][ny]) {
                    f[nx][ny] = f[current.first][current.second] + 1;
                    q.push({nx, ny});
                }
            }
        }

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
