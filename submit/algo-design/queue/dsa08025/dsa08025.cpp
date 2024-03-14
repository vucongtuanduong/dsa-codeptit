#include<bits/stdc++.h>
using namespace std;

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int minMoves(pair<int, int> start, pair<int, int> end) {
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                if (nx == end.first && ny == end.second) {
                    return dist[nx][ny];
                }
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, e;
        cin >> s >> e;
        pair<int, int> start = {s[0] - 'a', s[1] - '1'};
        pair<int, int> end = {e[0] - 'a', e[1] - '1'};
        cout << minMoves(start, end) << endl;
    }
    return 0;
}