#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-2,  -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
void testCase();
int minMoves(pair<int, int> start, pair<int, int> end);
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
int minMoves(pair<int, int> start, pair<int, int> end) {
    vector<vector<int>> dist(8, vector<int>(8, -1)); //8*8
    queue<pair<int,int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[current.first][current.second] + 1;
                if (nx == end.first && ny == end.second) {
                    return dist[nx][ny];
                }
            }
        }
    }
    return 0;
}
void testCase() {
    string s1, s2;
    cin >> s1 >> s2;
    pair<int, int> start = {s1[0] - 'a', s1[1] - '1'};
    pair<int, int> end = {s2[0] - 'a', s2[1] - '1'};
    cout << minMoves(start, end);
}