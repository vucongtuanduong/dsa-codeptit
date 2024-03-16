#include <bits/stdc++.h>
using namespace std;
void testCase();
int bfs(vector<vector<int>> &matrix, int n, int m);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
int bfs(vector<vector<int>> &matrix, int n, int m) {
    vector<vector<int>>visited(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    visited[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            return visited[x][y];
        }
        int steps = matrix[x][y];
        if (x + steps < n && visited[x + steps][y] == -1) {
            visited[x + steps][y] = visited[x][y] + 1;
            q.push({x +steps, y});
        }
        if (y + steps < m && visited[x][y + steps] == -1)  {
            visited[x][y + steps] = visited[x][y] + 1;
            q.push({x, y + steps});
        }
    }
    return -1;
}
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }   
        
    }
    cout << bfs(matrix, n, m);
}
