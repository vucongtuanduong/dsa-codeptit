#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};
int minMoves(pair<int, int> start, pair<int,int> end) {
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        for (int i = 0; i < 8; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && dist[new_x][new_y] == -1)  {
                dist[new_x][new_y] = dist[x][y] + 1;
                q.push({new_x, new_y});
            }
            if (new_x == end.first && new_y == end.second) {
                return dist[new_x][new_y];
            }
        }
    }
    return -1;
}
void testCase() {
    string a, b;
    cin >> a >> b;
    pair<int,int> start = {a[0] - 'a', a[1] - '1'};
    pair<int, int> end = {b[0] - 'a',  b[1] - '1'};
    cout << minMoves(start, end);
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
