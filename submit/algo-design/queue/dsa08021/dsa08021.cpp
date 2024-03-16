#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& matrix, int M, int N) {
    vector<vector<int>> visited(M, vector<int>(N, -1));
    queue<pair<int, int>> q;
    visited[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == M - 1 && y == N - 1) return visited[x][y];
        int steps = matrix[x][y];
        if (x + steps < M && visited[x + steps][y] == -1) {
            visited[x + steps][y] = visited[x][y] + 1;
            q.push({x + steps, y});
        }
        if (y + steps < N && visited[x][y + steps] == -1) {
            visited[x][y + steps] = visited[x][y] + 1;
            q.push({x, y + steps});
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<vector<int>> matrix(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << bfs(matrix, M, N) << endl;
    }
    return 0;
}