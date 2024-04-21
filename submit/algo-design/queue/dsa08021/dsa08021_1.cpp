#include <bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>> a, int n, int m) {
    vector<vector<int>> visited(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    visited[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            return visited[x][y];
        }
        int steps = a[x][y];
        int new_x = x + steps;
        int new_y = y + steps;
        if (new_x < n && visited[new_x][y] == -1) {
            visited[new_x][y] = visited[x][y] + 1;
            q.push({new_x, y});
        }
        if (new_y < m && visited[x][new_y] == -1) {
            visited[x][new_y] = visited[x][y] + 1;
            q.push({x, new_y});
        }

    }
    return -1;
}
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << bfs(a, n, m);
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
