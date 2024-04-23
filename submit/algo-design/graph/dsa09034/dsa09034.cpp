#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[8] = {-1, -1, -1, 0, 0, 1,1,1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(vector<string> &matrix, int i, int j, vector<vector<bool>> &visited) {
    visited[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == 'W') {
            if (!visited[nx][ny]) {
                dfs(matrix, nx, ny, visited);
            }
        }
    }
}
void testCase() {
    
    cin >> n >> m;
    vector<string> matrix;
    matrix.resize(n);
    cin.ignore();
    vector<vector<bool>> visited;
    visited.resize(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        getline(cin, matrix[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'W' && !visited[i][j]) {
                dfs(matrix, i, j, visited);
                cnt++;
            }
        }
    }
    cout << cnt;
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
