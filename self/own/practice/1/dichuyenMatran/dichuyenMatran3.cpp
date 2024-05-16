#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, 1};
vector<int> dy = {0, 1, 1};
bool isValid(int new_x, int new_y, int n, int m) {
    return(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m);
}
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({0, 0});
    vector<vector<int>> dist(n, vector<int>(m, 0));

    while (!q.empty()) {
        auto temp = q.front();
        int x = temp.first;
        int y = temp.second;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << dist[n - 1][m - 1];
            return;
        }
        for (int i = 0; i < 3; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            int len = 0;
            if (isValid(new_x, new_y, n, m)) {
                len = abs(a[new_x][new_y] - a[x][y]);
            }
            if (len > 0) {
                new_x = x + dx[i] * len;
                new_y = y + dy[i] * len;
                if (isValid(new_x, new_y, n, m) && dist[new_x][new_y] == 0) {
                    dist[new_x][new_y] = dist[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }

        }
    }
    cout << "-1";
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
