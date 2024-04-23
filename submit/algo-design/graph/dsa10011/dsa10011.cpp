#include <bits/stdc++.h>
using namespace std;
class Data {
    public:
        int x, y;
        int w;
        bool operator < (const Data& other) const {
            return this->w > other.w;
        }
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void dijkstra(vector<vector<int>> matrix, vector<vector<int>> &dist, int n, int m) {
    priority_queue<Data> pq;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        Data current = pq.top();
        pq.pop();
        for (int k = 0; k < 4; k++) {
            int nx = current.x + dx[k];
            int ny  = current.y  + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int nw = dist[current.x][current.y] + matrix[nx][ny];
                if (nw < dist[nx][ny]) {
                    dist[nx][ny] = nw;
                    pq.push({nx, ny, dist[nx][ny]});
                }
            }
        }
    }
}
void testCase() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    vector<vector<int>> dist;
    matrix.resize(n, vector<int> (m));
    dist.resize(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    dist[0][0] = matrix[0][0];
    dijkstra(matrix, dist, n, m);
    cout << dist[n - 1][m - 1];
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
