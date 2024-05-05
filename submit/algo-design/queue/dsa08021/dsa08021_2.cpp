#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1001][1001];
int bfs(int a[1001][1001]) {
    queue<pair<int,int>> q;
    vector<vector<int>> visited;
    visited.resize(n, vector<int> (m, -1));
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
        int newX = x + steps;
        int newY = y + steps;
        if (newX < n  && visited[newX][y] == -1) {
            q.push({newX, y});
            visited[newX][y] = visited[x][y] + 1;
        }
        if (newY < m && visited[x][newY] == -1) {
            q.push({x, newY});
            visited[x][newY] = visited[x][y] + 1;
        }
    }
    return -1;
    
}
void testCase() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << bfs(a);

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
