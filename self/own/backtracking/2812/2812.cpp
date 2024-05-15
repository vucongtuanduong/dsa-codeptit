#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &score, int n) {
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            pair<int,int> temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            int s = score[x][y];
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && score[new_x][new_y] > 1 + s) {
                    score[new_x][new_y] = 1 + s;
                    q.push({new_x, new_y});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        cin.tie(NULL);
        ios_base::sync_with_stdio;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> score(n, vector<int>(n, INT_MAX));
        bfs(grid, score, n);
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int,int>>>pq;
        pq.push({score[0][0], {0, 0}});
        while (!pq.empty()) {
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            if (temp.first == n - 1 && temp.second == n - 1) {
                return safe;
            }
            visited[temp.first][temp.second] = true;
            for (int i = 0; i < 4; i++) {
                int new_x = temp.first + dx[i];
                int new_y = temp.second + dy[i];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && !visited[new_x][new_y]) {
                    int  s = min(safe, score[new_x][new_y]);
                    pq.push({s, {new_x, new_y}});
                    visited[new_x][new_y] = true;
                }
            }
        }
        return -1;
    }
};
void testCase() {
    int n;
    cin >> n ;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Solution h;
    cout << h.maximumSafenessFactor(grid);
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
