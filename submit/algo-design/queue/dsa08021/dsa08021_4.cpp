#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j =0 ; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << dist[x][y];
            return;
        }
        int new_x = a[x][y] + x;
        int new_y = a[x][y] + y;
        if (new_x >= 0 && new_x < n && dist[new_x][y] == -1) {
            dist[new_x][y] = dist[x][y] + 1;
            q.push({new_x, y});
        }
        if (new_y >= 0 && new_y < m && dist[x][new_y] == -1) {
            dist[x][new_y] = dist[x][y] + 1;
            q.push({x, new_y});
        } 
    }
    cout << "-1";
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
